# Project Roadmap

## 01. Memory Pool Allocator
- Fixed-size memory allocation
- Deterministic memory management
- Avoiding dynamic heap usage
- Memory safety concepts

## 02. Ring Buffer
- Circular buffer implementation
- Producer-consumer communication
- Efficient data streaming
- Buffer overflow handling

## 03. Real-Time Scheduler
- Task control blocks
- Priority-based scheduling
- Timing constraints
- Deadline monitoring

## 04. Watchdog Timer
- Heartbeat monitoring
- Fault detection
- Automatic recovery mechanisms
- System supervision

## 05. Finite State Machine Framework
- Deterministic state transitions
- Event-driven architecture
- Embedded control logic
- Flight mode simulation

## 06. CRC & Error Detection
- Data integrity checks
- Communication reliability
- Error detection algorithms
- Packet validation

## 07. Fault Manager
- Fault detection
- Error logging
- Recovery strategies
- Safe-state handling

## 08. Triple Modular Redundancy (TMR)
- Redundant computation
- Majority voting
- Fault tolerance
- System reliability

## 09. Kalman Filter
- Sensor fusion
- State estimation
- Noise filtering
- Navigation concepts

## 10. Flight Computer Simulator
- Integration of all modules
- Simulated flight software architecture
- Real-time execution loop
- Fault injection testing

---

# Target Repository Structure

```text
flight-lab/
│
├── README.md
│
├── 01_memory_pool/
│   ├── Makefile
│   ├── include/
│   ├── src/
│   └── tests/
│
├── 02_ring_buffer/
│   ├── Makefile
│   ├── include/
│   ├── src/
│   └── tests/
│
├── 03_scheduler/
│   ├── Makefile
│   ├── include/
│   ├── src/
│   └── tests/
│
├── 04_watchdog/
│   ├── Makefile
│   ├── include/
│   ├── src/
│   └── tests/
│
├── 05_state_machine/
│   ├── Makefile
│   ├── include/
│   ├── src/
│   └── tests/
│
├── 06_crc/
│   ├── Makefile
│   ├── include/
│   ├── src/
│   └── tests/
│
├── 07_fault_manager/
│   ├── Makefile
│   ├── include/
│   ├── src/
│   └── tests/
│
├── 08_tmr/
│   ├── Makefile
│   ├── include/
│   ├── src/
│   └── tests/
│
├── 09_kalman/
│   ├── Makefile
│   ├── include/
│   ├── src/
│   └── tests/
│
└── 10_flight_computer/
    ├── Makefile
    ├── include/
    ├── src/
    └── tests/