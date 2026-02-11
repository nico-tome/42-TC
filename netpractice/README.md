*This project has been created as part of the 42 curriculum by ntome.*

# NetPractice

## Description

NetPractice is a networking training project from the 42 curriculum designed to develop a strong understanding of fundamental TCP/IP networking concepts.

The goal of the project is to configure small virtual network infrastructures by correctly assigning IP addresses, subnet masks, and default gateways in order to enable communication between hosts across different network topologies.

Each level presents a network diagram containing hosts, routers, and switches. The student must analyze the topology and configure the network parameters so that all required machines can communicate properly.

This project focuses entirely on networking logic and theory rather than programming.

---

## Objectives

- Understand IPv4 addressing
- Work with subnet masks and CIDR notation
- Perform subnet calculations
- Configure default gateways
- Understand routing between networks
- Identify broadcast and network addresses
- Analyze packet flow between hosts

---

## Instructions

### Running the Training Interface

The NetPractice interface runs locally in a browser environment.

To start the training interface:

```bash
./run.sh
```


Then open the provided local address in your web browser.

If run.sh is not executable:

chmod +x run.sh
./run.sh

### Solve a level

To complete a level you need to change `ip` and `mask` so the networking work properly. When it's done, a button appear to export your configuration that you need to put in your submission repo.

---

## Resources

I use a notion from `pjourdana`, great thanks to him !

I learn about `TCP/IP addressing`, `subnet masks`, `default gateway`, `routers` and `switches`.


### TCP/IP

**TCP/IP (Transmission Control Protocol / Internet Protocol)** is a set of communication protocols that enables computers to exchange data over networks, including the Internet.

It is structured in layers:

* **Application layer**: Handles protocols used by applications (HTTP, FTP, SMTP, DNS).
* **Transport layer**: Manages data transmission between hosts.

  * **TCP** ensures reliable, ordered delivery.
  * **UDP** provides faster, connectionless transmission without guarantees.
* **Internet layer**: Uses IP to assign addresses and route packets between networks.
* **Network access layer**: Transmits data over physical media (Ethernet, Wi-Fi).

In short, TCP/IP defines how data is addressed, transmitted, routed, and received across interconnected networks.


### Subnet masks

A **subnet mask** is a value used in IPv4 networking to divide an IP address into two parts: the **network portion** and the **host portion**.

It works alongside an IP address to determine:

* Which devices belong to the same network
* The valid host range
* The network and broadcast addresses

A subnet mask is written in dotted decimal format (e.g., `255.255.255.0`) or CIDR notation (e.g., `/24`).

The mask uses binary 1s to represent the network part and 0s for the host part.

Subnet masks allow large networks to be split into smaller, more manageable subnetworks, improving organization, performance, and routing efficiency.


## Default Gateway

A **default gateway** is the device (usually a router) that forwards traffic from a local network to other networks.

When a host wants to communicate with an IP address outside its own subnet, it sends the packet to the default gateway. The gateway then routes the packet toward its destination.

Each device in a network typically has:

* An IP address
* A subnet mask
* A default gateway

The default gateway must be in the same subnet as the host.

In short, the default gateway acts as the exit point from a local network to external networks, including the Internet.


### Routers

A **router** is a network device that connects multiple networks and forwards data between them.

It operates at **Layer 3 (Network layer)** of the OSI model and uses IP addresses to determine the best path for packet delivery.

Each router:

* Has multiple network interfaces
* Maintains a routing table
* Forwards packets based on destination IP addresses

Routers enable communication between different subnets and allow local networks to access external networks, including the Internet.

In short, a router directs traffic between networks and ensures data reaches its intended destination.


### Switches

A **switch** is a network device that connects multiple devices within the same local network.

It operates at **Layer 2 (Data Link layer)** of the OSI model and uses **MAC addresses** to forward frames to the correct device.

A switch:

* Learns MAC addresses dynamically
* Maintains a MAC address table
* Sends data only to the intended recipient (not to all devices)

Unlike a router, a switch does not route traffic between different networks. It only manages communication inside the same subnet.

In short, a switch efficiently connects devices within a local network and reduces unnecessary traffic.

---

## Submission Details

In order to submit this project, you need to push the 10 configurations from each exercices and this README file at the repository root.
