#include <jni.h>
#include <string>

using namespace std;

string string_to_hex(const string &input);

extern "C"
jstring
Java_com_sebamaty_storingsensitivedatainndkexample_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    string hello = string_to_hex("SAMPLE_AUTHENTICATION_DATA");
    return env->NewStringUTF(hello.c_str());
}

string string_to_hex(const string &input) {
    static const char *const lut = "0123456789ABCDEF";
    size_t len = input.length();

    string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i) {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}
