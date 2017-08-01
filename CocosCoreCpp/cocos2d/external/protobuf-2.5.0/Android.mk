LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE 	:= protobuf_static

LOCAL_MODULE_FILENAME := libprotobuf

TARGET_CPU_ABI := armeabi
#设置c++11头文件路径和链接路径
prebuilt_stdcxx_PATH := D:\android-ndk-r10b\sources\cxx-stl\gnu-libstdc++\4.8

LOCAL_C_INCLUDES := $(LOCAL_PATH)/src/google/protobuf/ \
					$(LOCAL_PATH)/src/google/protobuf/io \
					$(LOCAL_PATH)/src/google/protobuf/stubs \
					$(prebuilt_stdcxx_PATH)/include \
    				$(prebuilt_stdcxx_PATH)/libs/$(TARGET_CPU_ABI)/include \
					$(LOCAL_PATH)/src	

LOCAL_LDFLAGS += -L$(prebuilt_stdcxx_PATH)/libs/$(TARGET_CPU_ABI) -lgnustl_static -lsupc++

LOCAL_CPP_EXTENSION := .cc
LOCAL_SRC_FILES := \
src/google/protobuf/io/coded_stream.cc\
src/google/protobuf/stubs/common.cc \
src/google/protobuf/descriptor.cc \
src/google/protobuf/descriptor.pb.cc\
src/google/protobuf/descriptor_database.cc\
src/google/protobuf/dynamic_message.cc\
src/google/protobuf/extension_set.cc\
src/google/protobuf/extension_set_heavy.cc\
src/google/protobuf/generated_message_reflection.cc \
src/google/protobuf/generated_message_util.cc \
src/google/protobuf/io/gzip_stream.cc \
src/google/protobuf/compiler/importer.cc\
src/google/protobuf/message.cc\
src/google/protobuf/message_lite.cc \
src/google/protobuf/stubs/once.cc \
src/google/protobuf/compiler/parser.cc\
src/google/protobuf/io/printer.cc \
src/google/protobuf/reflection_ops.cc \
src/google/protobuf/repeated_field.cc \
src/google/protobuf/service.cc\
src/google/protobuf/stubs/structurally_valid.cc \
src/google/protobuf/stubs/strutil.cc\
src/google/protobuf/stubs/substitute.cc \
src/google/protobuf/stubs/stringprintf.cc \
src/google/protobuf/text_format.cc\
src/google/protobuf/io/tokenizer.cc \
src/google/protobuf/unknown_field_set.cc\
src/google/protobuf/wire_format.cc\
src/google/protobuf/wire_format_lite.cc \
src/google/protobuf/io/zero_copy_stream.cc\
src/google/protobuf/io/zero_copy_stream_impl.cc \
src/google/protobuf/io/zero_copy_stream_impl_lite.cc


#LOCAL_CFLAGS := -std=c99
#LOCAL_CFLAGS += -std=c++11 -stdlib=libstdc++ -Wno-error=c++11-narrowing
include $(BUILD_STATIC_LIBRARY)