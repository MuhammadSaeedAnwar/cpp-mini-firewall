#include <iostream>
#include <cstdlib>
#include <string>

void blockIP(const std::string& ip) {
#ifdef _WIN32
    std::string cmd = "netsh advfirewall firewall add rule name=\"BlockIP\" dir=in action=block remoteip=" + ip;
#else
    std::string cmd = "sudo iptables -A INPUT -s " + ip + " -j DROP";
#endif
    system(cmd.c_str());
    std::cout << "[+] Blocked IP: " << ip << std::endl;
}

void blockPort(int port) {
#ifdef _WIN32
    std::string cmd = "netsh advfirewall firewall add rule name=\"BlockPort\" dir=in action=block protocol=TCP localport=" + std::to_string(port);
#else
    std::string cmd = "sudo iptables -A INPUT -p tcp --dport " + std::to_string(port) + " -j DROP";
#endif
    system(cmd.c_str());
    std::cout << "[+] Blocked Port: " << port << std::endl;
}

void allowAll() {
#ifdef _WIN32
    std::string cmd = "netsh advfirewall reset";
#else
    std::string cmd = "sudo iptables -F";
#endif
    system(cmd.c_str());
    std::cout << "[+] Firewall reset: Allowed all traffic" << std::endl;
}

int main() {
    int choice;
    while (true) {
        std::cout << "\n=== Mini Firewall ===\n";
        std::cout << "1. Block IP\n";
        std::cout << "2. Block Port\n";
        std::cout << "3. Allow All (Reset)\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string ip;
            std::cout << "Enter IP to block: ";
            std::cin >> ip;
            blockIP(ip);
        } else if (choice == 2) {
            int port;
            std::cout << "Enter Port to block: ";
            std::cin >> port;
            blockPort(port);
        } else if (choice == 3) {
            allowAll();
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
    return 0;
}
