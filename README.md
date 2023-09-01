# CPP-5G-Network-Sim

A 5G Networking Simulator.

## Description

### 2021
The simulator models a SDNs, generate E-UTRAN Node B(Enode B) basestations includes:
1. MIMO Antennas
⋅⋅* transceivers, mini antennas and sectors.
2. Basestation Data
⋅⋅* Time, Direction, Signal Strength: SNR(Signal to Noise Ratio), and location of UE(user devices)
#### Variables
1. Mobility ID: MIN [Stationary]0-----[Walk]1-----[Car]2> MAX, Mobility Buffer defines the rate of updates of the UE location.
2. RSRP(Referebce Signal Received Power): To find the Basestation provide most resources, worst user with lowest RSRP in vector get optimize first.
3. DDR(Data Drop Rate): Simulate the Data Loss in the network.

### 2022
The simulator realistically models channel conditions, power calculation, key performance indicators (KPIs), and BaseStation (BS) to User Equipment (UE) interactions. By measuring the KPIs of a specific UE and detecting the status of nearby BSs, optimal algorithmic decisions can be made by the network manager to transfer users from one BS to another. By doing so, the network can optimize and heal itself when unfavorable events or conditions occur.
#### GUI Updates
1. Femto Cell and Pico Cell
2.  

### 2023


This project uses the [GTK](https://www.gtk.org/) library for the GUI.

## Key Terms

+ Key Performance Indicators (KPIs)
+ BaseStation (BS)
+ User Equipment (UE)

## Links

[Documentation](https://github.com/cpptromar/CPP-5G-Network-Sim/tree/master/doc/Documentation)
[Changelogs](https://github.com/cpptromar/CPP-5G-Network-Sim/tree/master/doc/Changelogs)
[Simulator Setup](https://github.com/cpptromar/CPP-5G-Network-Sim/tree/master/doc/Documentation/Simulator_Setup.docx)
