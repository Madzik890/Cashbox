#include "udpreceiptsender.hpp"
#include "../core/exceptions/receiptsenderexception.hpp"

#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

using namespace Domain::Network::Infrastructure;
using namespace Domain::Network::Core::Exceptions;


UdpRecepitSender::UdpRecepitSender(const std::string &ip, const int &port)
    :Core::Ports::Outgoing::IReceiptSender(),
     _ip(ip), _port(port)
{

}

UdpRecepitSender::~UdpRecepitSender()
{

}

void UdpRecepitSender::sendReceipt(const Shopping::Core::Models::ReceiptModel &receipt)
{
    struct sockaddr_in serwer =
    {
        .sin_family = AF_INET,
        .sin_port = htons( _port )
    };

    if( inet_pton( AF_INET, _ip.c_str(), & serwer.sin_addr ) <= 0 )
        throw ReceiptSenderException( "inet_pton() ERROR" );

    const int socket_ = socket( AF_INET, SOCK_DGRAM, 0 );
    if( socket_ < 0 )
        throw ReceiptSenderException( "socket() ERROR" );

    socklen_t len = sizeof( serwer );

    const std::string receiptString = receipt.toString();
    const int receiptSize = receiptString.size();
    if( sendto( socket_, receiptString.c_str(), receiptSize, 0,( struct sockaddr * ) & serwer, len ) < 0 )
        throw ReceiptSenderException( "sendto() ERROR" );
}
