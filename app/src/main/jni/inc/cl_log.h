#include <android/log.h>
#include <string.h>

#ifndef _CL_LOG_H_
#define _CL_LOG_H_

#define LOG_ENABLE 1 // The log enable

#if LOG_ENABLE
#define TAG "CLIB_LOG"
#define FILENAME(path) strrchr(path, '/') ? strrchr(path, '/') + 1 : path
#define LOG(level, tag, fmt, args...) \
	do { \
		__android_log_print(level, tag, "[%s:%s:%d]: "\
		fmt, FILENAME(__FILE__), __FUNCTION__, __LINE__, ##args ); \
	} while (0)
#define LOGI(fmt, args...) LOG(ANDROID_LOG_INFO, TAG, fmt, ##args)
#define LOGD(fmt, args...) LOG(ANDROID_LOG_DEBUG, TAG, fmt, ##args)
#define LOGE(fmt, args...) LOG(ANDROID_LOG_ERROR, TAG, fmt, ##args)
#else
#define LOGI(fmt, args...)
#define LOGD(fmt, args...)
#define LOGE(fmt, args...)
#define LOG(level, tag, fmt, args...)
#endif //LOG_ENABLE

#endif //_CL_LOG_H_