cmake_minimum_required(VERSION 3.25)
project(Lab_7)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_7 PacketParserMain.cpp UdpPacketParser.cpp PacketParser.h TcpPacketParser.cpp TcpPacketParser.h UdpPacketParser.h)
