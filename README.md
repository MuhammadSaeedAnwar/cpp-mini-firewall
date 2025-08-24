# Mini Firewall C++ Command-Line Tool

A lightweight cross-platform **Mini Firewall** written in C++ that lets you block IP addresses or ports using system firewall commands.  
--
## Features

- Block traffic from a specific **IP address**
- Block traffic on a specific **Port**
- Reset rules to allow all traffic
- Works on **Windows** and **Linux/macOS**
- ----
## Command Prompt Demo

**When you run the executable:**

=== Mini Firewall ===

Block IP

Block Port

Allow All (Reset)

Exit
Enter choice: 1
Enter IP to block: 192.168.1.100
Blocked IP: 192.168.1.100

=== Mini Firewall ===

Block IP

Block Port

Allow All (Reset)

Exit
Enter choice: 2
Enter Port to block: 8080
Blocked Port: 8080

=== Mini Firewall ===

Block IP

Block Port

Allow All (Reset)

Exit
Enter choice: 3
Allowed all traffic (Reset rules)
---
## How to Compile & Run

### Linux/macOS
```bash
g++ firewall.cpp -o firewall
sudo ./firewall

Open **Command Prompt (Admin)** and run:

**g++ firewall.cpp -o firewall.exe**
**firewall.exe**
