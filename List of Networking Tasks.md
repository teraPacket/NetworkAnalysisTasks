Note:  
* Some tasks have an artificial number in the description just to make it look clear, such as "Detect all ongoing ping sweep: show the hosts who are doing ICMP ping requests on greater than 10 hosts". 
* When we say "the session identified by a given packet number", we mean the TCP/UDP session that contains the packet with the given packet number.


##L2/L3:
* Detect a change on IP header TTL values among packets in a TCP session, the change is >= 10. This is possible Man-On-The-Side attack.
* Exclude packets in a pcap to/from a list of countries.
* Detect host scanning by ARP or IP (ICMP).
* Detect port knock attempts: instance where 3 TCP SYN packets for the server ports 1000 2000 3000 of the same server IP within 1 second.
* Detect ARP requests that are not answered.
* Detect ARP requests that are answered more than once within 100ms.
* Detect ARP requests that has unsolicited ARP response.
* Detect the evidence of possible ARP poisoning: list the hosts with MAC address change.

##TCP/UDP/ICMP
* Capture all packets for all sessions whose server port is 6667 (IRC).  (donot count the sessions whose client port is 6667). 
* Capture packets to/from server ports 6660 - 6669.
* Capture all packets for all sessions whose server IP is 1.2.3.4. 
* Capture packets from/to a list (thousands) of IP addresses.
* Find all the TCP sessions that didn’t finish: no FIN or RST.
* Find all the TCP sessions that finish with TCP RST.
* Find all the TCP sessions that has complete tear down sequence, FINACK, FINACK, ACK.  <a href="https://ask.wireshark.org/questions/40953/filter-for-all-connections">Ask Wireshark question</a>
* Extract TCP sessions whose first data are from the server side.
* Detect sessions with retransmitted SYNACK after TCP client sent data.
* Find TCP sessions that are established but with TCP SYN retries.
* Get all packets of all complete TCP sessions:  TCP sessions with tcp handshake, data packet(s) and FIN packet(s).
* Find all ICMP ping requests that didn’t get responded.
* Find all the UDP packets that got ICMP packet: port-unreachable.
* Find TCP sessions where the client sent more data in total than the server.
* Detect packet drop on a stream of UDP packets whose payload has an increment counter.
* Detect Man-On-The-Side attack on a HTTP transaction by checking the latency between request and response time (if it’s less than ½ of TCP handshake time).
* Detect Man-On-The-Side attack on a HTTP transaction by checking sequence number and checksum: the response from the real server and the injected response will have the same sequence number but not the same checksum.
* Detect all the ping sweep: show the hosts who are doing ICMP ping requests on greater than 10 hosts.
* Detect TCP port scanning.
* Detect UDP port scanning.
* Remove tcp packets on sessions which started before capturing is started, in another word, remove packets belonging to sessions not having either SYN or SYNACK packet.
* Detect a type of RAT where the pattern is a repetition of the following:  server sent a msg and client replies immediately (within 1 second).
* Detect Skype Login, where the client exchanges UDP messages with a server and then, it sent about 10 UDP messages to different servers all at once (within 0.1 second).
* Detect Slowloris attack: HTTP session, but each piece of data from client is < 10 bytes
* Detect slow DHCP transactions where latency is greater than 0.5 second.
* Detect slow DHCP transaction and transaction that resulted in DHCP NAK. 
* Find all TCP sessions that has at least 3 packets with windowSize being 0
* Extract both retransmitted packets and the original packets in a session.
* Find all TCP sessions whose combined client or combined server data match a string.
* Find all TCP sessions whose combined client or combined server data match a regular expression.
* Find all TCP sessions whose combined client or combined server data match a pattern after base64 decoding.
* Find all TCP sessions whose combined client or combined server data match a pattern after gunzip.
* Show all the complete TCP sessions (has SYN, FINACK packets), whose total duration is greater than 100 seconds.
* Show all TCP sessions with at least 100 packets.
* Show all complete TCP sessions that never even had one data packet
* List all unique IP addresses in a pcap
* List all unique server IP addresses in a pcap
* List all unique IP addresses in a pcap, these IP addresses acted both as clients and as servers.
* Save all TCP data from server in a session to a file. The session is identified by a given packet number.
* Given a packet number, save the TCP data from the server in a session to a file starting from the given packet.
* Deduplicate packets in TCP/UDP sessions without specifying how far back we need to compare against.
* Save a pcap with  IP fragments into a new pcap where all IP fragments are reassebled.
* Find TCP sessions where the first data is from client and it's 6 seconds after tcp handshake
* Find TCP sessions where the server sent FINACK immediately after TCP handshake.
* Find TCP sessions where the server just sent TCP SYNACK, no other packets but clint sent data and retransmit.
* Find TCP sessions where the server sent TCP RST on the first client data.


##DNS
* Extract the DNS requests that have slow DNS responses (latencies > 1 second).
* Extract the DNS transactions whose response has an error.
* Extract the DNS requests that never got a reply.
* Extract the DNS transactions where there are more than one response packets for the request.
* Extract the DNS requests which resulted in ICMP (port-unreachable, destionation-unreachable or others)
* Find hosts whose DNS requests resulted in >= 5 errors.
* Find hosts that sent a burst of DNS requests:  more than 10 in 2 seconds.
* Find DNS transactions whose response has A record whose TTL is small: < 30 seconds
* Find DNS requests to a given domain. 
* Find DNS requests for A-record whose responses has more than 10 resolved IPs
* Find DNS requests trying to resolve a hostname but not using it in subsequent HTTP requests.
* Detect the DNS requests sent to IP addresses other than a given list of 10.

##HTTP
* Find TCP sessions to server port 80 or 8080 but request does not begin with any of the HTTP key word.
* Find TCP sessions to server port 80 or 8080 but response does not begin with HTTP/1.x
* Find HTTP transactions not using the standard server ports: 80, 8080
* Find HTTP transactions using certain proxy.
* Extract HTTP requests where the response code are 500 or above.
* Extract HTTP requests whose responses is TCP RST
* Extract HTTP requests whose response body is an exe, flash, pdf or zip file.
* Extract HTTP transactions that has response code of 100 among others.
* Host that sent the same HTTP POST body to 5 different servers within 2 seconds.
* Find all HTTP requests whose Host field is IP instead of a host name.
* Find all HTTP requests that has less than 4 headers.
* Show HTTP transactions of hosts with at least 3 HTTP User-Agents.
* Detect HTTP download of an exe with XOR obfuscation (XOR with a 8 byte string)
* Find the web site that has the highest number of requests to it.
* Find the chain of HTTP requests that lead to a given HTTP request, identified by the packet number of the request.
* Find all the HTTP transactions to a particular domain, say,  *.facebook.com
* HTTP response that claims to be text/html, but actually doesnot have &lt;html&gt; tag even after gunzip.
* List the distributions/frequencies of HTTP response codes.
* For a HTTP request (identified by packet number), save the HTTP response.
* For all HTTP POST requests, save the full URI and post body to a file
* List all HTTP requests whose URI extensions is not one of js, css, xml, png, jpg.
* Find HTTP transactions whose first-byte response time is greater than 2.0 seconds.
* List all domains visited in all HTTP transactions and the frequency of each.
* Save files in HTTP upload given the packet number of the first data packet of the HTTP request.
* Find HTTP requests that are not replied.
* Find HTTP requests that caused TCP RST.
* Show all the HTTP requests to a list of 10 countries.
* List all unique HTTP URLs in a pcap
* Detect instances where HTTP redirect is not followed, could be a sign of some malware. 
* Detect HTTP responses that display system error messages like a stack trace on Java.
* Detect all HTTP requests whose User-Agent length is less than 10.
* Detect HTTP requests whose URI has "?" but HTTP request doesn't have a referer header.
* Detect HTTP POST requests but HTTP request doesn't have a referer header.
* Detect multiple HTTP requests on the same TCP connection, the second request doesn't have a Referer header.
* Detect the HTTP GET requests that come in greater than 2 pieces and each piece is less than 1000 bytes
* Detect the HTTP POST requests whose total size is less than 3000 bytes but it took 10 seconds in sending all pieces
* Detect the presence of pipeline HTTP requests
* Detect TCP session with HTTP transaction, where handshake is extremely fast (<= 2ms) but HTTP response is very slow (>=2 seconds)
* Detect HTTP transaction where HTTP response body is just an IP address.
* Detect HTTP transaction where HTTP response claims to be text/html according to content-type, but it doesn't have any tags (<...>)
* Detect HTTP transactions where the first 4 bytes in HTTP body are binary (no printable character)


##SSL
* TCP sessions to server port 443, but not SSL handshake, list all the first data packet.
* Detect complete SSL session, not on a set of known ports, 443 or 4433.
* Detect SSL sessions that has started SSL handshake but never sent any application data.
* Extract all the SSL server certificates.
* Detect Tor from SSL traffic.
* Detect Heartbleed attack.
* List all unique SSL common names.
* Detect the session where SSL client-hello get TCP FIN or RST.

##Other application protocols
* SMTP:  Extract all email recipients from a given SMTP session identified by a packet number.
* SMTP:  Extract all the email senders in a pcap file.
* SMTP:  List all the senders or email subject (if any) to a given list of email recipients.
* SMTP:  Extract email attachment.
* SMTP: Detect aborted SMTP sessions: never sent any mail data.
* SMTP: Extract all the mail data. 
* SMTP: Given a recipient email address, find the sender email address and subject in the SMTP session.
* SMTP: Detect the case when more than 5 SMTP sessions from a host in a minute
* FTP:  Follow FTP session (control and data session)
* FTP:  Extract data downloaded or uploaded.
* TFTP:  Extract data downloaded or uploaded.
* Detect AIM by checking if certain fields of packets are incrementing counter.
* Detected failed manual SSH login based on the pattern that, client and server initially exchange a bunch messages quickly(within half a second), then clienet sends a message and gets a reply, but client does not send any message for 3 seconds.
* Find the TCP sessions where server port is 21 (for FTP) but the first data packet in the session is from client.
* 

##C&C
* Client and server has long sessions (duration > 5min) with 10 pairs of interactive messages. 
* Detect long TCP sessions (say, duration is greater than 5 minutes) where server side sent a sequence of small messages (possibly a list of command for bot), say, the server messages are all smaller than 100 bytes.
* The second HTTP request in a TCP session has "x-flash-version" header.
* a TCP session with at least two HTTP transaction, the first one has resp code 404,  the second request has the same URI as the first one.

##Extraction
* Save all TCP or UDP packets from a pcap into a new pcap with only the headers MAC, IP, TCP/UDP/ICMP
* Variant of above:  Save all TCP or UDP packets from a pcap into a new pcap with only the headers MAC, IP, TCP/UDP/ICMP, except for DNS packets, where the entire packets are saved.
* Save packets in GTP tunnel into a new pcap so that the tunnel layer is removed.
* Save packets encapsulated using TZSP so that the tunnel layer is removed.
* Display telnet session by remove duplicate bytes. (which makes it hard to see what’s the command user typed)
* A client tried some site and getting a non-200 response, then it tried some other sites with the same URI or hostname in URI.
* HTTP POST request claims (via "Content-Type") Post data is www-form-urlencoded, but it's actually not.
* HTTP response whose Content-Type is "text/html", but the data doesn't have a tag.
* HTTP transaction where client sent FIN or RST after server sent HTTP header but before entire HTTP response was sent.

#Charting
* Chart the HTTP response latencies.
* Chart on TCP handshake latencies

