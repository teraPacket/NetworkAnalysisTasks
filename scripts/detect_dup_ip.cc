static i2m_Map ip2mac; //map from ip to its MAC

pkt:
    if (eth.type != ARP) return 0;
    if (arp.opcode == ARP_REPLY) {
        if (ip2mac[arp.src.proto_ipv4] == 0) {
            ip2mac[arp.src.proto_ipv4] = eth.src;
        } else if (ip2mac[arp.src.proto_ipv4] != eth.src) {
            notify("dup IP %b at pkt %3d\n", arp.src.proto_ipv4,pktNum);
    
        }
    }
