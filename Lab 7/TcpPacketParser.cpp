//
// Created by Sthapanavichet on 7/8/2023.
//
//
// Created by Sthapanavichet on 7/8/2023.
//
#include "TcpPacketParser.h"
#include <cstring>
#include <iomanip>
TcpPacketParser::TcpPacketParser() {
    source_port = 0;
    dest_port = 0;
    sequence_number = 0;
    ack_number = 0;
    length = 0;
    checksum = 0;
    data = nullptr;
}

bool TcpPacketParser::parse(const char *packet) {
    source_port = (packet[0] << 8) + packet[1];
    dest_port = (packet[2] << 8) + packet[3];
    sequence_number = (packet[4] << 24) + (packet[5] << 16) + (packet[6] << 8) + packet[7];
    ack_number = (packet[8] << 24) + (packet[9] << 16) + (packet[10] << 8) + packet[11];
    checksum = (packet[16] << 8) + packet[17];
    length = (packet[20] << 8) + packet[21];
    int packetSum = source_port + dest_port + length + sequence_number + ack_number;
    if(packetSum != checksum) return false;
    data = new char[length+1];
    std::memcpy(data, &packet[22], length);
    data[length] = '\0';
    return true;
}

void TcpPacketParser::display(std::ostream &os) const {
    int spacing = 13;
    std::cout << "Report for UDP Packet Parser" << std::endl;
    std::cout.setf(std::ios::left);
    std::cout << std::setw(spacing) << "source port: " << source_port << std::endl;
    std::cout << std::setw(spacing) << "dest port: " << dest_port << std::endl;
    std::cout << std::setw(spacing) << "seq number: " << sequence_number << std::endl;
    std::cout << std::setw(spacing) << "ack number: " << ack_number << std::endl;
    std::cout << std::setw(spacing) << "data length: " << length << std::endl;
    std::cout << std::setw(spacing) << "data:" << data << std::endl;
}

TcpPacketParser::~TcpPacketParser() {
    source_port = 0;
    dest_port = 0;
    sequence_number = 0;
    ack_number = 0;
    length = 0;
    checksum = 0;
    delete []data;
    data = nullptr;
}