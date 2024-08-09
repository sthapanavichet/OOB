//
// Created by Sthapanavichet on 7/9/2023.
//

#ifndef LAB_7_TCPPACKETPARSER_H
#define LAB_7_TCPPACKETPARSER_H

#include "PacketParser.h"

class TcpPacketParser : public PacketParser {
    int source_port;
    int dest_port;
    int sequence_number;
    int ack_number;
    int length;
    int checksum;
    char *data;
public:
    TcpPacketParser();
    bool parse(const char *packet) override;
    void display(std::ostream &os) const override;
    ~TcpPacketParser();
};

#endif //LAB_7_TCPPACKETPARSER_H
