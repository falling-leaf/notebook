### Homework-1

### Name: Wang Haoyuan

### Number: 3220105114

#### Problem 1

Imagine that you have trained your St. Bernard, Bernie, to carry a box of three 8-mm tapes instead of a flask of brandy. (When your disk fills up, you consider that an emergency.) These tapes each contain 7 gigabytes. The dog can travel to your side, wherever you may be, at 18 km/hour. For what range of distances does Bernie have a higher data rate than a transmission line whose data rate (excluding overhead) is 150 Mbps?

How does your answer change if

(i) Bernie’s speed is doubled;

(ii) each tape capacity is doubled;

(iii) the data rate of the transmission line is doubled.

Answer:

Suppose the distance is $D$, the capacity of the box is $C$, the speed of the dog is $v$, the transmission line is $R$, then:

$$
\frac{C}{\frac{D}{v}} \geq R
$$

so we have:

$$
\frac{3 \cdot 7 \cdot 8 \cdot 1000 Mb}{\frac{D} {\frac{18}{3.6}} m/s} \geq 150Mbps
$$

the answer is: $D \leq 5600m$

(i): consider the relation of $v$ and $D$, so the answer is: $D \leq 2 \times 5600m = 11200m$

(ii): consider the relation of $C$ and $D$, so the answer is: $D \leq 2 \times 5600m = 11200m$

(iii): consider the relation of $R$ and $D$, so the answer is: $D \leq \frac{5600m}{2} = 2800m$

#### Problem 2

What are two reasons for using layered protocols? What is one possible disadvantage of using layered protocols?

Answer:

First, because of the high speed of technical development, the technology of different layers changes fast. Using layered protocols is able to control the change of one layer inside the protocol of this layer. That means, if one layer's protocol needs to be changed, other layer's protocol won't be affected. Besides, different layers can be implemented with different methods, and the structure of the computer is complicated, so it is almost impossible to find a stable and complete protocol for the whole computer. Using layered protocols can solve the problem of compatibility and make the protocols more easy to be set.

Second, by using layered protocols, we can devide the whole tranformation task into several sub-tasks, which will be more efficient when considering the collaboration between people or even corporations. 

One possible disadvantage of using layered protocols is that we need to design interfaces between every two neighbor layers. That will cost much time and that may cause some problem when we put all the layered protocols together and check whether the protocols work.

#### Problem 3

In some networks, the data link layer handles transmission errors by requesting that damaged frames be retransmitted. If the probability of a frame’s being damaged is p, what is the mean number of transmissions required to send a frame? Assume that acknowledgements are never lost.

Answer:

So we set the number of transmissions is $N$, because even retransmitted frame may be damaged, so we have:

$$
N = 1 + p + p^2 + ... = \sum_{i = 0}^{\infty}p^i = \frac{1}{1-p}
$$

#### Problem 4

What is the main difference between TCP and UDP?

Answer:

The main difference of TCP and UDP is the process of connection:

- for TCP, it needs to be connected before transforming the message(handshake for three times). In that way, the transformation of the information will be more reliable, but the efficiency of TCP is less than that of UDP.
- for UDP, it transforms data without connecting between two devices, so the speed of transformation is fast. However, the reliability of the message cannot be guaranteed.

#### Problem 5

How long was a bit in the original 802.3 standard in meters? Use a transmission speed of 10 Mbps and assume the propagation speed in coax is 2/3 the speed of light in vacuum.

Answer:

We know that for bit length we have:

$$

bit~length = \frac{propagation~speed}{transmission~speed}

$$

so the answer is:

$$

bit~length = \frac{\frac{2}{3} \times 3 \times 10^8m/s}{10 \times 1000 \times 1000 bps} = 20m

$$

#### Problem 6

List one advantage and one disadvantage of having international standards for network protocols.

Answer:

- The advantage of international standard is that we can build connections of devices all over the world without adjusting between different protocols, that means we have a better capatability. Devices which follow international standards can be connected with foreign devices, which brings convenience of information transformation.
- The disadvantage of international standard is that the space of innovation is restricted. If the standard itself is not that good, it is hard to be replaced. Apart from it, most of the devices need to obey the standard, some devices which don't satisfy the standard will be hard to connect into the Internet. If these devices have better performance, then international standard may become the main problem.

#### Problem 7

Which layers are common in the OSI model and TCP/IP model?

Answer:

These layers below are common in the OSI model(7 layers in total) and TCP/IP model(4 layers in total):

- network layer
- transport layer
