#pragma comment(lib,"curl/libcurl.a")

#include <cstdio>

#include "curl/include/curl/curl.h"

const char URL[] = "https://www.baidu.com";

FILE* fp;

size_t Write(void* ptr, size_t size, size_t nmemb, void* stream) {
  int written = fwrite(ptr, size, nmemb, (FILE*)fp);
  return written;
}

void Download() {
  CURL* curl;
  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
  curl_easy_setopt(curl, CURLOPT_URL, URL);

  if ((fp = fopen("tmp", "w")) == NULL) {
    curl_easy_cleanup(curl);
    return;
  }

  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Write);
  curl_easy_perform(curl);
  curl_easy_cleanup(curl);

  return;
}

int main() {
  Download();
}
