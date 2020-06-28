from typing import Dict
from typing import List
from script.config import BuildTarget
from script.config import ClusterConfig
from script.config import NodeConfig
from script.run_bash_script import RunSingleCommandInNode

def BuildVars(cluster_config: ClusterConfig,
              node_configs: Dict[str, NodeConfig],
              build_targets: List[BuildTarget]) -> Dict[str, str]:
  result = dict()
  
  result["{{kubernetes_master_location}}"] = \
    node_configs[cluster_config.kubernetes_master].location
  
  result["{{postgres_citus_master_location}}"] = \
    node_configs[cluster_config.postgres_citus_master].location
  result["{{postgres_citus_master_port}}"] = \
    cluster_config.postgres_citus_master_port
  result["{{postgres_citus_master_user}}"] = \
    cluster_config.postgres_citus_master_user
  result["{{postgres_citus_master_password}}"] = \
    cluster_config.postgres_citus_master_password

  result["{{deployment_master_location}}"] = \
    node_configs[cluster_config.deployment_master].location
  
  deployment_registry_prefix = "{0}:{1}/"\
    .format(node_configs[cluster_config.deployment_master].location,
            cluster_config.deployment_image_registry_port)

  for build_target in build_targets:
    if not build_target.pushable:
      continue
    build_target_var_key = "{{" + build_target.name + "_image}}"
    build_target_var_val = deployment_registry_prefix + build_target.name
    result[build_target_var_key] = build_target_var_val

  return result

def ReplaceVarNamesWithValues(content: str, vars: Dict[str, str]) -> str:
  for entry in vars.items():
      content = content.replace(entry[0], entry[1])
  return content

class TemplateInstantiator:
  def __init__(self,
                cluster_config: ClusterConfig,
                node_configs: Dict[str, NodeConfig],
                build_targets: List[BuildTarget]):
    self.vars_ = BuildVars(cluster_config, node_configs, build_targets)
  
  def __ReadTemplateFile(self, 
                         template_file_path: str, 
                         target_node: NodeConfig):
    if target_node is None:
      with open(template_file_path, "r") as template_file:
        return template_file.read()
      assert(False)
    else:
      content = RunSingleCommandInNode(
        node=target_node, 
        command="cat {0}".format(template_file_path), 
        retrieve_output=True)
      assert(content)
      return content
  
  def __WriteInstantiatedFile(self,
                              content: str,
                              instantiated_file_path: str,
                              target_node):
    if target_node is None:
      with open(instantiated_file_path, "w") as instantiated_file:
        instantiated_file.write(content)
        return
      assert(True)
    else:
      RunSingleCommandInNode(
        node=target_node, 
        command="echo -e \"{0}\" > {1}"
          .format(content, instantiated_file_path))

  def Instantiate(self, 
                  template_file_path: str,
                  target_node: NodeConfig) -> str:
    instantiated_file_path = template_file_path.replace(".tmpl", "")
    assert(instantiated_file_path != template_file_path)

    content = self.__ReadTemplateFile(template_file_path, target_node)
    instantiated = ReplaceVarNamesWithValues(content, self.vars_)
    self.__WriteInstantiatedFile(instantiated, 
                                 instantiated_file_path,
                                 target_node)

    return instantiated_file_path

