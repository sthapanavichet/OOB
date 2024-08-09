//
// Created by Sthapanavichet on 7/8/2023.
//
#include "UdpPacketParser.h"
#include <cstring>
#include <iomanip>
UdpPacketParser::UdpPacketParser() {
    source_port = 0;
    dest_port = 0;
    length = 0;
    checksum = 0;
    data = nullptr;
}

bool UdpPacketParser::parse(const char *packet) {
    source_port = (packet[0] << 8) + packet[1];
    dest_port = (packet[2] << 8) + packet[3];
    length = (packet[4] << 8) + packet[5];
    checksum = (packet[6] << 8) + packet[7];
    int packetSum = source_port + dest_port + length;
    if(packetSum != checksum) return false;
    data = new char[length+1];
    std::memcpy(data, &packet[8], length);
    data[length] = '\0';
    return true;
}

void UdpPacketParser::display(std::ostream &os) const {
    int spacing = 13;
    std::cout << "Report for UDP Packet Parser" << std::endl;
    std::cout.setf(std::ios::left);
    std::cout << std::setw(spacing) << "source port: " << source_port << std::endl;
    std::cout << std::setw(spacing) << "dest port: " << dest_port << std::endl;
    std::cout << std::setw(spacing) << "data length: " << length << std::endl;
    std::cout << std::setw(spacing) << "data:" << data << std::endl;
}

UdpPacketParser::~UdpPacketParser() {
    source_port = 0;
    dest_port = 0;
    length = 0;
    checksum = 0;
    delete []data;
    data = nullptr;
}

std::ostream &operator<<(std::ostream &os, PacketParser &parser) {
    parser.display(os);
    return os;
};