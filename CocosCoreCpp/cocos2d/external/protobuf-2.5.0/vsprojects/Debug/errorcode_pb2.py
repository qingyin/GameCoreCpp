# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: errorcode.proto

from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)




DESCRIPTOR = _descriptor.FileDescriptor(
  name='errorcode.proto',
  package='pb',
  serialized_pb='\n\x0f\x65rrorcode.proto\x12\x02pb*\xbe\x03\n\tErrorCode\x12\x0e\n\nERROR_NONE\x10\x00\x12\x18\n\x14\x45RROR_SERVER_CLOSING\x10\x01\x12\x1c\n\x18\x45RROR_SERVER_MAINTAINING\x10\x02\x12\x16\n\x12\x45RROR_SYSTEM_ERROR\x10\x05\x12\x15\n\x11\x45RROR_BAD_REQUEST\x10\x06\x12\x1c\n\x18\x45RROR_PROTOCOL_UNMATCHED\x10\x07\x12\x1b\n\x17\x45RROR_SYSTEM_NOT_UNLOCK\x10\x08\x12\x18\n\x14\x45RROR_USER_NOT_LOGIN\x10\x0b\x12\x18\n\x14\x45RROR_USER_FORBIDDEN\x10\x0c\x12\x1f\n\x1b\x45RROR_USER_WAITING_RESPONSE\x10\r\x12\x1a\n\x16\x45RROR_PLAYER_NOT_EXIST\x10\x14\x12\x1a\n\x16\x45RROR_PLAYERNAME_EXIST\x10\x15\x12 \n\x1c\x45RROR_PLAYER_ALREADY_CREATED\x10\x16\x12\x1a\n\x16\x45RROR_NICKNAME_INVALID\x10\x17\x12\x1a\n\x16\x45RROR_PLAYER_NOT_LOGIN\x10\x18\x12\x18\n\x14\x45RROR_NICKNAME_EXIST\x10\x19')

_ERRORCODE = _descriptor.EnumDescriptor(
  name='ErrorCode',
  full_name='pb.ErrorCode',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='ERROR_NONE', index=0, number=0,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ERROR_SERVER_CLOSING', index=1, number=1,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ERROR_SERVER_MAINTAINING', index=2, number=2,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ERROR_SYSTEM_ERROR', index=3, number=5,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ERROR_BAD_REQUEST', index=4, number=6,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ERROR_PROTOCOL_UNMATCHED', index=5, number=7,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ERROR_SYSTEM_NOT_UNLOCK', index=6, number=8,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ERROR_USER_NOT_LOGIN', index=7, number=11,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ERROR_USER_FORBIDDEN', index=8, number=12,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ERROR_USER_WAITING_RESPONSE', index=9, number=13,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ERROR_PLAYER_NOT_EXIST', index=10, number=20,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ERROR_PLAYERNAME_EXIST', index=11, number=21,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ERROR_PLAYER_ALREADY_CREATED', index=12, number=22,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ERROR_NICKNAME_INVALID', index=13, number=23,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ERROR_PLAYER_NOT_LOGIN', index=14, number=24,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ERROR_NICKNAME_EXIST', index=15, number=25,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=24,
  serialized_end=470,
)

ErrorCode = enum_type_wrapper.EnumTypeWrapper(_ERRORCODE)
ERROR_NONE = 0
ERROR_SERVER_CLOSING = 1
ERROR_SERVER_MAINTAINING = 2
ERROR_SYSTEM_ERROR = 5
ERROR_BAD_REQUEST = 6
ERROR_PROTOCOL_UNMATCHED = 7
ERROR_SYSTEM_NOT_UNLOCK = 8
ERROR_USER_NOT_LOGIN = 11
ERROR_USER_FORBIDDEN = 12
ERROR_USER_WAITING_RESPONSE = 13
ERROR_PLAYER_NOT_EXIST = 20
ERROR_PLAYERNAME_EXIST = 21
ERROR_PLAYER_ALREADY_CREATED = 22
ERROR_NICKNAME_INVALID = 23
ERROR_PLAYER_NOT_LOGIN = 24
ERROR_NICKNAME_EXIST = 25




# @@protoc_insertion_point(module_scope)
