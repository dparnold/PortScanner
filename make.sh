#!/bin/bash
g++ -c PortScanner.cpp && g++ PortScanner.o -o PortScanner -lsfml-system -lsfml-network && ./PortScanner

