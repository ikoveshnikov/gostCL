#include "errormessages.h"

std::string GetErrorMessage(int errorCode)
{
    switch (errorCode) {
    case -1:
        return std::string ("Not implemented");
        break;

    case 0:
        return std::string ("Successfully done. No error found");
        break;

    case 1:
        return std::string ("Cannot set user defined SBoxes: format is wrong");
        break;

    case 2:
        return std::string ("Encryption key is not set");
        break;

    case 3:
        return std::string ("Such standart sboxes don't exist");
        break;

    case 4:
        return std::string ("Mode of operation is unknown");
        break;

    case 5:
        return std::string ("Unexpected null pointer got!");
        break;

    case 6:
        return std::string ("");
        break;

    case 101:
        return std::string ("OpenCL error: CL_DEVICE_NOT_FOUND");
        break;

    case 102:
        return std::string ("OpenCL error: CL_DEVICE_NOT_AVAILABLE");
        break;

    case 103:
        return std::string ("OpenCL error: CL_COMPILER_NOT_AVAILABLE");
        break;

    case 104:
        return std::string ("OpenCL error: CL_MEM_OBJECT_ALLOCATION_FAILURE");
        break;

    case 105:
        return std::string ("OpenCL error: CL_OUT_OF_RESOURCES");
        break;

    case 106:
        return std::string ("OpenCL error: CL_OUT_OF_HOST_MEMORY");
        break;

    case 107:
        return std::string ("OpenCL error: CL_PROFILING_INFO_NOT_AVAILABLE");
        break;

    case 108:
        return std::string ("OpenCL error: CL_MEM_COPY_OVERLAP");
        break;

    case 109:
        return std::string ("OpenCL error: CL_IMAGE_FORMAT_MISMATCH");
        break;

    case 110:
        return std::string ("OpenCL error: CL_IMAGE_FORMAT_NOT_SUPPORTED");
        break;

    case 111:
        return std::string ("OpenCL error: CL_BUILD_PROGRAM_FAILURE");
        break;

    case 112:
        return std::string ("OpenCL error: CL_MAP_FAILURE");
        break;

    case 113:
        return std::string ("OpenCL error: CL_MISALIGNED_SUB_BUFFER_OFFSET");
        break;

    case 114:
        return std::string ("OpenCL error: CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST");
        break;

    case 115:
        return std::string ("OpenCL error: CL_COMPILE_PROGRAM_FAILURE");
        break;

    case 116:
        return std::string ("OpenCL error: CL_LINKER_NOT_AVAILABLE");
        break;

    case 117:
        return std::string ("OpenCL error: CL_LINK_PROGRAM_FAILURE");
        break;

    case 118:
        return std::string ("OpenCL error: CL_DEVICE_PARTITION_FAILED");
        break;

    case 119:
        return std::string ("OpenCL error: CL_KERNEL_ARG_INFO_NOT_AVAILABLE");
        break;

    case 130:
        return std::string ("OpenCL error: CL_INVALID_VALUE");
        break;

    case 131:
        return std::string ("OpenCL error: CL_INVALID_DEVICE_TYPE");
        break;

    case 132:
        return std::string ("OpenCL error: CL_INVALID_PLATFORM");
        break;

    case 133:
        return std::string ("OpenCL error: CL_INVALID_DEVICE");
        break;

    case 134:
        return std::string ("OpenCL error: CL_INVALID_CONTEXT");
        break;

    case 135:
        return std::string ("OpenCL error: CL_INVALID_QUEUE_PROPERTIES");
        break;

    case 136:
        return std::string ("OpenCL error: CL_INVALID_COMMAND_QUEUE");
        break;

    case 137:
        return std::string ("OpenCL error: CL_INVALID_HOST_PTR");
        break;

    case 138:
        return std::string ("OpenCL error: CL_INVALID_MEM_OBJECT");
        break;

    case 139:
        return std::string ("OpenCL error: CL_INVALID_IMAGE_FORMAT_DESCRIPTOR");
        break;

    case 140:
        return std::string ("OpenCL error: CL_INVALID_IMAGE_SIZE");
        break;

    case 141:
        return std::string ("OpenCL error: CL_INVALID_SAMPLER");
        break;

    case 142:
        return std::string ("OpenCL error: CL_INVALID_BINARY");
        break;

    case 143:
        return std::string ("OpenCL error: CL_INVALID_BUILD_OPTIONS");
        break;

    case 144:
        return std::string ("OpenCL error: CL_INVALID_PROGRAM");
        break;

    case 145:
        return std::string ("OpenCL error: CL_INVALID_PROGRAM_EXECUTABLE");
        break;

    case 146:
        return std::string ("OpenCL error: CL_INVALID_KERNEL_NAME");
        break;

    case 147:
        return std::string ("OpenCL error: CL_INVALID_KERNEL_DEFINITION");
        break;

    case 148:
        return std::string ("OpenCL error: CL_INVALID_KERNEL");
        break;

    case 149:
        return std::string ("OpenCL error: CL_INVALID_ARG_INDEX");
        break;

    case 150:
        return std::string ("OpenCL error: CL_INVALID_ARG_VALUE");
        break;

    case 151:
        return std::string ("OpenCL error: CL_INVALID_ARG_SIZE");
        break;

    case 152:
        return std::string ("OpenCL error: CL_INVALID_KERNEL_ARGS");
        break;

    case 153:
        return std::string ("OpenCL error: CL_INVALID_WORK_DIMENSION");
        break;

    case 154:
        return std::string ("OpenCL error: CL_INVALID_WORK_GROUP_SIZE");
        break;

    case 155:
        return std::string ("OpenCL error: CL_INVALID_WORK_ITEM_SIZE");
        break;

    case 156:
        return std::string ("OpenCL error: CL_INVALID_GLOBAL_OFFSET");
        break;

    case 157:
        return std::string ("OpenCL error: CL_INVALID_EVENT_WAIT_LIST");
        break;

    case 158:
        return std::string ("OpenCL error: CL_INVALID_EVENT");
        break;

    case 159:
        return std::string ("OpenCL error: CL_INVALID_OPERATION");
        break;

    case 160:
        return std::string ("OpenCL error: CL_INVALID_GL_OBJECT");
        break;

    case 161:
        return std::string ("OpenCL error: CL_INVALID_BUFFER_SIZE");
        break;

    case 162:
        return std::string ("OpenCL error: CL_INVALID_MIP_LEVEL");
        break;

    case 163:
        return std::string ("OpenCL error: CL_INVALID_GLOBAL_WORK_SIZE");
        break;

    case 164:
        return std::string ("OpenCL error: CL_INVALID_PROPERTY");
        break;

    case 165:
        return std::string ("OpenCL error: CL_INVALID_IMAGE_DESCRIPTOR");
        break;

    case 166:
        return std::string ("OpenCL error: CL_INVALID_COMPILER_OPTIONS");
        break;

    case 167:
        return std::string ("OpenCL error: CL_INVALID_LINKER_OPTIONS");
        break;

    case 168:
        return std::string ("OpenCL error: CL_INVALID_DEVICE_PARTITION_COUNT");
        break;


    default:
        return std::string ("Unknown error");
        break;
    }
}


