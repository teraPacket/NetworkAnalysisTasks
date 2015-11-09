


##L2/L3:
* Detect possible arp poisoning by checking “destination MAC” of some hosts have changed.
* Detect big change on IP header TTL in a TCP session. Possible Man-On-The-Side attack.
* Exclude packets in a packets to/from a list of countries.
* Detect host scanning by ARP or IP (ICMP).
* Detect port knock attempt
* Detect ARP request that’s not answered.

##TCP/UDP/ICMP
* Capture all packets for all sessions whose server port is 6667 (IRC).  (how to avoid the sessions whose client port is 6667?) 
* Capture packets to/from server ports 6660 - 6669
* Capture all packets for all sessions whose server IP is 1.2.3.4? 
* Capture packets from/to a list (thousands) of IP addresses?
* Find all the TCP sessions that didn’t finish: no FIN or RESET
* Find all the TCP sessions that finish with TCP RESET
* Detect sessions with retransmitted SYNACK after TCP client sent data.
* Find TCP sessions that established but with TCP SYN retries.
* Get all packets of all complete TCP sessions:  TCP sessions that start with TCP SYN packet and with data packet. Src.
* Find ICMP ping requests that didn’t get responded
* Find TCP sessions where client sent more data than server
* Detect packet drop on stream of UDP packets whose payload has an increment counter.
* Detect Man-On-The-Side by checking response time (if it’s less than ½ of TCP handshake time)
* Detect Man-On-The-Side by checking sequence number and checksum: the response from the real server and the injected response will have the same sequence number.
* Detect all ongoing ping sweep: show the hosts who are doing ICMP ping requests on multiple hosts.
* Detect port scanning by either TCP or UDP
* Detect a type of RAT where server sent the first msg and repeats the pattern where server sent a msg and client replies immediately.
* Detect Skype Login, where the client exchanges UDP messages with a server and then, it sent about 10 UDP messages to different servers.
* Detect Slowloris attack.
* Detect Slow DHCP transactions.
* Find TCP sessions that has at least 3 packets with windowSize being 0
* Extract both retransmitted packets and the original packets in a session.
* Match data spaning over multiple packets
* Save all TCP data from server in a session to a file.
* Deduplicate TCP/UDP sessions without specifying how far back we need to compare against.
* Save a pcap with  IP fragments into a new pcap where ip fragments are reassebled.
* Find all the UDP packets that got ICMP port-unreachable back.

##DNS
* Extract the DNS requests that have slow DNS responses.
* Extract the DNS transactions where responses has an error.
* Extract the DNS transactions where there are more than one response packets
* Extract the DNS requests which resulted in ICMP.
* Find hosts whose DNS requests resulted in >= 5 errors.
* Find hosts that sent a burst of DNS requests:  more than 10 in 5 seconds.
* Find DNS transactions whose response has A record whose TTL is small: < 30 seconds
* Find DNS requests for A-record whose responses has more than 10 resolved IPs
* Find DNS requests trying to resolve a hostname but not using it in subsequent HTTP requests.
* Detect if DNS requests were sent to unexpected DNS servers.

##HTTP
* Find TCP sessions to server port 8080 but 
* Request is not HTTP
* Response is not HTTP
* Find HTTP transactions not using standard server ports: 80, 8080
* Find HTTP transactions using certain proxy.
* Extract HTTP requests based on responses
* Response is 500 or above
* Got TCP RESET
* Response body is an exe, flash, pdf or zip file.
* Response body that’s not a text file, but the 8 bytes from offset 32 is the * same as offset 40. (XORed exe)
* Extract HTTP transactions that has response of 100 in it.
* Host that sent the same HTTP POST to different servers with 5 seconds.
* Find all HTTP requests whose Host field is IP, also have their responses.
* Find all HTTP requests that have less than 4 headers.
* Show HTTP transactions of hosts with at least 3 HTTP User-Agents.
* Detect HTTP download of an exe with XOR obfuscation (XOR with 8 bytes)
* Find the most popular web site.
* Find the chain of HTTP requests that lead to a particular HTTP request (for example: an infecting HTTP request).
* Find all the HTTP transactions to a particular domain, say,  *.facebook.com
* Find HTTP request with less than n header fields, for example, n=4
* HTTP response that claims to be text/html, but actually not
* List HTTP response code distributions/frequencies
* For each HTTP request (in UI), save the HTTP response by point-n-click
* For all HTTP POST requests, save the full URI and post body.
* List all HTTP requests that skip a list of extensions, js, css, xml, png, jpg..
* Find HTTP transactions whose first-byte response time is greater than x seconds.
* Find HTTP requests whose Host field is IP
* List all domains visited in all HTTP transactions, and frequency of each
* Save files in HTTP upload
* Find HTTP requests that are not replied.
* Show all the HTTP requests to certain countries.
* Show all the complete TCP sessions (has SYN, FINACK packets), whose total duration is greater than 100 seconds.
* Show all TCP sessions with at least 100 packets.
* List all unique IP addresses in a pcap
* List all full HTTP URLs in a pcap
* Detect instances where HTTP redirect is not followed, could be sign of some malware. 

##SSL
* sessions to server port 443, but not SSL, list all the first data packet
* Detect SSL session, not on a set of known ports, 443.
* Extract server certificates
* Detect Tor from SSL traffic
* Detect Heartbleed attack.
* List all unique SSL common names
* Detect the session where SSL client-hello get TCP FIN or RST.

##Other application protocols
* SMTP:  Extract all email recipients from SMTP session.
* SMTP:  Extract email attachment
* SMTP: detect aborted SMTP sessions: with less than 5 TCP data packet
* SMTP: extract all the mail data
* FTP:  Follow FTP session (control and data session)
* FTP:  Extract data downloaded or uploaded.
* TFTP:  Extract data downloaded or uploaded.
* Detect AIM by checking if certain fields of packets are incrementing counter.
* Detected failed manual SSH login based on the pattern that, client and server initially exchange a bunch messages quickly, then after 

##C&C
* client and server has long sessions with interactive messages
* In a long session, server side sent messages that are short (a list of command for bot).
Misc
* session that whose first data is from server side


##Extraction
* save all TCP or UDP packets with only the headers MAC, IP, TCP/UDP/ICMP
* Variant of above:  DNS is exception, save the entire packets
* Save packets in GTP tunnel
* Save packets encapsulated using TZSP. Example.
* Display telnet session by remove duplicate bytes. (which makes it hard to see what’s the command user typed)

#Charting
* Chart the HTTP response latencies.
* Chart on TCP handshake latencies

