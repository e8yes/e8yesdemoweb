TEMPLATE = subdirs
SUBDIRS = \
    unit_test_util \
    container/container.pro \
    container_test/trie_map_test \
    container_test/lru_hash_map_test \
    flags \
    test_flags

CONFIG += ordered
