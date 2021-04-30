#include <curl/curl.h>
#include <iostream>
#include <string>

/* Writes the contents into a string */
size_t CurlWrite_CallbackFunc_StdString(void* contents, size_t size, size_t nmemb, std::string* s)
{
    size_t newLength = size * nmemb;
    try
    {
        s->append((char*)contents, newLength);
    }
    catch (std::bad_alloc& e)
    {
        std::cout << "Not enough memory" << std::endl;
        return 0;
    }
    return newLength;
}

int main(void)
{
    std::cout << "Starting" << std::endl;
    std::string s;
    CURL* curl;
    CURLcode res;

    /* In windows, this will init the winsock stuff */
    curl_global_init(CURL_GLOBAL_ALL);

    /* Get a curl handle */
    curl = curl_easy_init();
    if (curl) {
        /* Set the URL that is about to receive our POST*/
        curl_easy_setopt(curl, CURLOPT_URL, "http://192.168.56.1:9099/api/matlab_run_cmd");
        /* Specify the POST data */
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "a=5&b=3");

        /* Specify write function to write response to*/
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWrite_CallbackFunc_StdString);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);

        std::cout << "Sending request" << std::endl;
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check the return code */
        if (res != CURLE_OK) {
            std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        std::cout << "Request finished" << std::endl;
        std::cout << "Response: " << s << std::endl;
        /* Cleanup */
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}
