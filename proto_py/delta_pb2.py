# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: delta.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='delta.proto',
  package='e8',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=_b('\n\x0b\x64\x65lta.proto\x12\x02\x65\x38*L\n\x0e\x44\x65ltaOperation\x12\x0f\n\x0b\x44OP_INVALID\x10\x00\x12\x0b\n\x07\x44OP_ADD\x10\x01\x12\x0e\n\nDOP_DELETE\x10\x02\x12\x0c\n\x08\x44OP_SWAP\x10\x03\x62\x06proto3')
)

_DELTAOPERATION = _descriptor.EnumDescriptor(
  name='DeltaOperation',
  full_name='e8.DeltaOperation',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='DOP_INVALID', index=0, number=0,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DOP_ADD', index=1, number=1,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DOP_DELETE', index=2, number=2,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DOP_SWAP', index=3, number=3,
      serialized_options=None,
      type=None),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=19,
  serialized_end=95,
)
_sym_db.RegisterEnumDescriptor(_DELTAOPERATION)

DeltaOperation = enum_type_wrapper.EnumTypeWrapper(_DELTAOPERATION)
DOP_INVALID = 0
DOP_ADD = 1
DOP_DELETE = 2
DOP_SWAP = 3


DESCRIPTOR.enum_types_by_name['DeltaOperation'] = _DELTAOPERATION
_sym_db.RegisterFileDescriptor(DESCRIPTOR)


# @@protoc_insertion_point(module_scope)
