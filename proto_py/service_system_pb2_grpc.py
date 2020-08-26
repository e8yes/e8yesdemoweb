# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
import grpc

import service_system_pb2 as service__system__pb2


class SystemServiceStub(object):
  # missing associated documentation comment in .proto file
  pass

  def __init__(self, channel):
    """Constructor.

    Args:
      channel: A grpc.Channel.
    """
    self.Version = channel.unary_unary(
        '/e8.SystemService/Version',
        request_serializer=service__system__pb2.VersionResquest.SerializeToString,
        response_deserializer=service__system__pb2.VersionResponse.FromString,
        )


class SystemServiceServicer(object):
  # missing associated documentation comment in .proto file
  pass

  def Version(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')


def add_SystemServiceServicer_to_server(servicer, server):
  rpc_method_handlers = {
      'Version': grpc.unary_unary_rpc_method_handler(
          servicer.Version,
          request_deserializer=service__system__pb2.VersionResquest.FromString,
          response_serializer=service__system__pb2.VersionResponse.SerializeToString,
      ),
  }
  generic_handler = grpc.method_handlers_generic_handler(
      'e8.SystemService', rpc_method_handlers)
  server.add_generic_rpc_handlers((generic_handler,))
