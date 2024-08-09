//
// Created by Sthapanavichet on 7/9/2023.
//

#ifndef LAB_7_UDPPACKETPARSER_H
#define LAB_7_UDPPACKETPARSER_H

#include "PacketParser.h"

class UdpPacketParser : public PacketParser {
    int source_port;
    int dest_port;
    int length;
    int checksum;
    char *data;
public:
    UdpPacketParser();
    bool parse(const char *packet) override;
    void display(std::ostream &os) const override;
    ~UdpPacketParser();
};

std::ostream &operator<<(std::ostream &os, PacketParser &parser);
#endif //LAB_7_UDPPACKETPARSER_H
