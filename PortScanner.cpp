#include <iostream>
#include <string>
#include <SFML/Network.hpp>
using namespace std;

string ip = "192.168.2.104";


bool port_is_open(const string &address, int port) // &: call by reference 
{
    sf::TcpSocket socket; // new instance of socket
    bool open = (socket.connect(sf::IpAddress(address), port) == sf::Socket::Done); // check whether the port is connenction is accepted
    socket.disconnect(); 
    return open;
}

void scan_range(int start, int end){
	int port;
	int portCounter = 0;
	cout << "Scanning from port " << start <<" to port " << end << " at "<< ip<<"\n";
	for(port =start;port<=end;port++){
		
		if(port_is_open(ip,port)){
			cout << "Port "<< port <<" is open at "<< ip <<" \n";
			portCounter ++;
		}
		cout << "Scanning port:\t " << port << "\n";
		cout << "\033[1A"; // jump up one line

	}
	cout << "\033[K"; // erase to end of line
	cout << "Scan completed! ";
	if(portCounter == 0){
		cout << "No open ports found.\n";
	}
	else{
		cout << "Open ports found:  "<< portCounter<<"\n";
	 }
}

void full_scan(){
	cout << "Full scan: ";
	scan_range(0,65535);
}

int main(){
	int start;
	int end;
	int typeOfScan;
	bool correctTypeOfScanInput = true ;
	cout << "Enter address for port scan: ";
	cin >> ip;
	do{
		cout << "What ports would you like to scan?\n";
		cout << "Type: \t 1 for complete scan\n";
		cout << "\t 2 for a specific range\n";
		cin >> typeOfScan;
		switch (typeOfScan){
			case 1:
				full_scan();
				break;
			case 2:
				cout << "Enter start port: ";
				cin >> start;
				cout << "Enter end port: ";
				cin >> end;		
				scan_range(start,end);
				break;
			default:
				correctTypeOfScanInput= false;
				cout <<"Invalid input!\n";	
		}
	}while(!correctTypeOfScanInput);
}
