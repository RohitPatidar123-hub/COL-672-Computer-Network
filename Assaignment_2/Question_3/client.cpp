#include <algorithm>
#include <arpa/inet.h>
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include<sstream>
#include<string>
#include <fstream>
// #include <jsoncpp/json/json.h>
#include<iostream>
#include <netinet/in.h>
#include <nlohmann/json.hpp>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
pthread_mutex_t mutex;
#define BUFFER_SIZE 10240
using json = nlohmann::json; 
using namespace std;

int to_int(string);




int main(int n,int *pro[])
{
            if(n!=2)
             {
                std::cout<<"Please enter corect input paramater \n";
                std::cout<<"Your Input be like ./client <protocol> \n";
                return 1;
             };
            string protocol = argv[1];
           // int n = to_int(pro[2]);
            
            std::ifstream config_file("config.json");
            if (!config_file.is_open())
            {
                    std::cout << "Failed to open config.json\n";
                    return -1;
            }

            json config;
            config_file >> config;

            std::string IP = config["server_ip"];
            int PORT = config["server_port"];
            int MAX_WORDS = config["k"];
            int SLOT_TIME = config["T"];
            int num_clients=config["nums_clients"];    
            int p=config["p"];
            





};
int to_int(string str)
{
        int num=0;
        for (int i = 0; str[i] != '\0'; i++) 
        {
            if (str[i] >= 48 && str[i] <= 57)
             {
                   num = num * 10 + (str[i] - 48);
             }
        else {
            break;
             }
         }
         return num;
};