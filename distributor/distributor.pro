TEMPLATE = subdirs
SUBDIRS = \
    store/node_state_store.pro \
    store_test/node_state_store_test \
    store_test/peer_store_test \
    mutation_propagator/mutation_propagator.pro \
    distributor/distributor.pro \
    distributor_test

CONFIG += ordered