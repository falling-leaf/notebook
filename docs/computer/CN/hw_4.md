<center>Homework 4</center>

<center>Name: Wang Haoyuan</center>

<center>Number: 3220105114</center>

#### Problem 1

A group of N stations share a 56-kbps pure ALOHA channel. Each station outputs a 1000-bit frame on average once every 100 sec, even if the previous one has not yet been sent (e.g., the stations can buffer outgoing frames). What is the maximum value of N?

**Answer:**

We know that after analyzing, the effectiveness of ALOHA is $0.184$, so the usable bandwidth is:

$$

56kbps \times 0.184 = 10.304kbps

$$

for each station, transform 1000 bits per 100 sec, so the needed bandwidth is:

$$

\frac{1000 bits}{100 sec} = 10bps

$$

So the maximum value of N is:

$$

N = \lfloor\frac{10.304kbps}{10bps}\rfloor = 1030 

$$


#### Problem 2

Consider the delay of pure ALOHA versus slotted ALOHA at low load. Which one is less? Explain your answer.

**Answer:**

We need to consider the low-load environment:

At low load:

1. For pure ALOHA, transmission can start instantly. Because of the low load, we can suppose that no collisions will happen, so the transmission is likely to be successful.

2. For slotted ALOHA, it has to wait for the start of next slot if it wants to be sent at the middle of the slot, and that will introduce more overhead.

In summary, the delay of pure ALOHA is less than that of slotted ALOHA at low load.

#### Problem 3

Sixteen stations, numbered 1 through 16, are contending for the use of a shared channel by using the adaptive tree walk protocol. If all the stations whose addresses are prime numbers suddenly become ready at once, how many bit slots are needed to resolve the contention?

**Answer:**

From 1 to 16, the prim numbers are: 2, 3, 5, 7, 11, 13.

Using the adaptive tree walk protocol, we can try to solve the problem of contention:

slot 1: get 2, 3, 5, 7, 11, 13

slot 2: choose from 2, 3, 5, 7

slot 3: choose from 2, 3

slot 4: choose 2

slot 5: choose 3

slot 6: choose from 5, 7

slot 7: choose 5

slot 8: choose 7

slot 9: choose from 11, 13

slot 10: choose 11

slot 11: choose 13

So in all, it needs **11** bit slots to resolve the contention.

#### Problem 4

Six stations, A through F, communicate using the MACA protocol. Is it possible for two transmissions to take place simultaneously? Explain your answer.

**Answer:**

Yes. It is possible for two transmissions to take place simultaneously.

For example, suppose A to F are in a straight line: that means, A contact with B, B contact with C and so on.

So when A and B transfer to each other, E and F can also transfer to each other at the same time.

Thus, it is possible for two transmissions to take place simultaneously.

#### Problem 5

Consider building a CSMA/CD network running at 1Gbps over a 1-km cable with no repeaters. The signal speed in the cable is 200,000 km/sec. What is the minimum frame size?

**Answer:**

We know that the minimum frame size is:

$$

n = 2 \times speed \times timespan

$$

So providing that the signal speed and the cable length, we know that the timespan is:

$$

t = \frac{1km}{200000km/sec} = 5usec

$$

So the minimum frame size is:

$$

n = 2 \times 10^9bps \times 5usec = 10000 bits

$$

(or, $1250$ bytes)


#### Problem 6

Please show the differences between:

(a) The Ethernet CSMA/CD protocol and the 802.11 CSMA/CA protocol

(b) The MACA protocol and the 802.11 CSMA/CA protocol

**Answer:**

(a): For CSMA/CD and CSMA/CA, they are different in the basis of method. 

1. From the method: CSMA/CD tries to detect the collision while transforming data, and improve the transmission rate. CSMA/CA tries to avoid the collision while transforming data, and can be adaptable to wireless environment.

2. From the result: CSMA/CD only reduces the recovery time, and CSMA/CA reduce the possibility of collision.

3. From the data sending time: CSMA/CD resends the data when conflict occurs, and CSMA/CA need first transmit the intent, and then send the data.

(b): For MACA and CSMA/CA, they are different in the method of collision avoidance.

1. From the method: MACA uses RTS and CTS messages to avoid collision, and CSMA/CA uses virtual carrier sensing and physical carrier sensing to avoid collisions.

2. From the purpose: MACA is designed for solving the hidden and exposed terminal problems, and CSMA/CA is designed for solving the collision avoidance problem in wireless local area networks.

3. From the reliability: MACA is unreliable because it only ensures the data transmission, but cannot guarantee the correct reception, and CSMA/CA uses ACK to confirm the reception of data, so it is reliable.

#### Problem 7

An unscrupulous host, A, connected to an 802.3 (Ethernet) network biases their implementation of the binary exponential backoff algorithm so they always choose from {0,1} after a collision, in any situation. Another host, B, is trying to send a frame at the same time as A. Assuming A and B collide exactly three times before one of their transmissions succeeds, what are the odds that B sends its frame before A(as opposed to A sending before B)?

**Answer:**

We know that A and B collide exactly three times, so the next time, B will choose from {0, 1, ..., $2^3-1$ = 7}, while A will choose from {0, 1}.

So there is only one case if B wants to send its frame before A(on the basis of that we know that B and A only collide three times):

1. B chooses 0, A chooses 1, the possibility is:

$$

p1 = \frac{1}{8 \times 2 - 2} = \frac{1}{14}

$$

So the answer is: $\frac{1}{14}$ 

#### Problem 8

Consider the following wireless network, where the circles are showing transmission ranges, and the presence of a host (letter) in a particular circle indicates it can hear that transmitter. If hosts A and C are both trying to send to host B will they encounter the hidden or exposed station problems? Does the MACA protocol help in this situation?

**Answer:**

The network in the figure will encounter the hidden station problem:

if C send message to B, A will not detect the use of bandwidth, so it will also send data to B or C if neccessary. In that case, a collision will happen.

The MACA protocol can help in this situation:

if using MACA protocol, after C sends RTS to B, then B will send CTS to C.

So when B sends CTS, A will get this message and knows that the bandwidth is busy.

So A won't send data when B and C transform the data, as a result the collision won't happen.

#### Problem 9

Consider the extended LAN connected using bridges B1
and B2in Fig. 4-33(b). Suppose the hash tables in the two bridges are empty. List all ports on which a packet will be forwarded for the following sequence of data transmissions:

(a) A sends a packet to C.

(b) E sends a packet to F.

(c) F sends a packet to E.

(d) G sends a packet to E.

(e) D sends a packet to A.

(f) B sends a packet to F.

**Answer:**

(a): because all the hash tables are empty, the packet will be forwarded to all the ports on the LAN.

So A will be sent from 2, 3, 4 port in B1 and 1, 2, 3 port in B2.

(b): E and F are unknown to B1 and B2:

So E will be sent from 1, 3, 4 port in B2 and 1, 2, 3 port in B1.

(c): because B2 knows E is on port 2:

So B1 and B2 will not forward the packet.

(d): because B2 knows E is on port 2:

So G will be sent from 2 port in B2.

(e): because B1 and B2 know the position of A:

So D will be sent from 4 port in B2 and 1 port in B1.

(f) B1 doesn't know the position of F:

So B will be sent from 1, 3, 4 port in B1 and 2 port in B2.