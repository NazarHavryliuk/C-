#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// ������� ��� ������ ����� � ������� �� HTTP-�����
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* buffer) {
    size_t totalSize = size * nmemb;
    buffer->append((char*)contents, totalSize);
    return totalSize;
}

// ������� ��� ��������� ���� BTC � API Bybit
std::string getBTCPrice() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        // ������������ URL ��� ������
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.bybit.com/v2/public/tickers?symbol=BTCUSD");

        // ������������ ������� ��� ������� ������
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // ��������� ������
        res = curl_easy_perform(curl);

        // �������� �� �������
        if (res != CURLE_OK) {
            std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
        }

        // ���������� ������ cURL
        curl_easy_cleanup(curl);
    }

    return readBuffer;
}

int main() {
    // �������� ������� �� API Bybit
    std::string response = getBTCPrice();

    // ������� JSON ������
    auto jsonData = json::parse(response);

    // �������� ���� BTC
    if (jsonData["result"].is_array() && !jsonData["result"].empty()) {
        auto tickerData = jsonData["result"][0];
        std::string lastPrice = tickerData["last_price"];
        std::cout << "Current BTC price: " << lastPrice << std::endl;
    }
    else {
        std::cerr << "Failed to get BTC price from Bybit API" << std::endl;
    }

    return 0;
}
