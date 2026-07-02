"""# Project Specification Document: Smart Student Service Centre Management System

## Course: SOF105 Data Structure (Academic Session 2026/04)

### Institution: Xiamen University Malaysia — Office of Academic Affairs

---

## 1. Project Overview & Objective

The objective of this assignment is to design, implement, and analyze a **Smart Student Service Centre Management System** using the C programming language. The application simulates a real-world university service desk where students request support for various academic and administrative tasks (e.g., course registration help, exam slip printing, fee payment inquiries, IT account support, and general academic inquiries).

The project is structured into two core parts, each contributing 50% to the total score:

1. **Group Component (50%):** Collaborative software engineering, system implementation, documentation, and operational integration.
2. **Individual Component (50%):** Deep-dive asymptotic runtime and space complexity analysis of a selected data structure across specific system tasks.

---

## 2. General Project Requirements & Constraints

To receive full credit, the system must adhere strictly to the following parameters:

- **Programming Language:** Must be written exclusively in standard **C**. Pre-built container libraries or high-level abstractions are prohibited.
- **Implementation Style:** The entire data management engine must be built **manually** from scratch using fundamental building blocks:
  - `struct` definitions for data modeling.
  - Pointers for memory management and linking.
  - Dynamic memory allocation (`malloc`, `free`) to manage memory lifecycles seamlessly and prevent memory leaks.
- **Collaboration Constraints:** Form a group of **3 to 5 members** (subject to lecturer confirmation).
- **Submission Deadline:** **03/07/2026**. Late submissions are penalized per course policy.

---

## 3. Data Structure Architectures

The system leverages three distinctive abstract data types (ADTs), each carefully mapped to a real-life operation in the student service center:

### A. Waiting Queue (FIFO - First In, First Out)

- **Purpose:** Manages students who are currently waiting to be served.
- **Node/Element Data Fields:**
  - Student ID (e.g., integer or string)
  - Student Name (string)
  - Service Type (e.g., Course Registration, Exam Slip, IT Support)
  - Priority Level (Enum/String: `Normal` or `Urgent`)
- **Core Operational Requirements:**
  - _Enqueue:_ Add a incoming student request to the rear of the queue.
  - _Dequeue:_ Remove the student at the front of the queue when a staff member becomes available to serve them.
  - _Display:_ Print out a sequential list of all currently waiting students with their associated metadata.

### B. Completed Service Linked List (Sequential Log)

- **Purpose:** Stores a historical, persistent record of all successfully processed student services.
- **Node/Element Data Fields:**
  - Student ID
  - Student Name
  - Service Type
  - Service Status
- **Core Operational Requirements:**
  - _Insert:_ Append or prepend a newly completed service record transferred directly from the waiting queue.
  - _Display All:_ Sequentially traverse and print every completed record currently recorded in the system logs.
  - _Search by ID:_ Perform a lookup traversal to find and display matching records using a Student ID.
  - _Count:_ Accumulate and return the cumulative integer total of completed service records.

### C. Undo Stack (LIFO - Last In, First Out)

- **Purpose:** Tracks recently completed services to handle mistakes, facilitating an instant error-correction mechanism.
- **Core Operational Requirements:**
  - _Push:_ When a student is served, their transaction node must be pushed onto the stack concurrently with its insertion into the completed linked list.
  - _removeelement:_ Remove the top element when an undo command is executed.

---

## 4. Integrated System Menu Options

The unified application must feature an interactive, looping console menu with built-in input validation. The menu must explicitly contain the following minimum functions:

1.  **Add New Student Request:** Enqueues a new student record into the waiting queue. Prompt for ID, name, service type, and priority level.
2.  **Serve Next Student:** Extracts the front student from the waiting queue (Dequeue), logs their record into the completed linked list (Insert), and archives the action on the undo history structure (Push).
3.  **Display Waiting Queue:** Prints the active queue formatted orderly from front to rear.
4.  **Display Completed Services:** Lists all historical data entries stored within the linked list.
5.  **Search Completed Service by Student ID:** Prompts for an ID and traverses the linked list to pinpoint matching elements.
6.  **Undo Last Completed Service:** Intercepts administrative errors. Pops the most recent item from the Stack, programmatically locates and purges that exact record from the Completed Linked List, and enqueues the student record back into the front/rear of the Waiting Queue.
7.  **Display System Summary:** Provides metrics like current waiting count, total processed items, and recent metrics.
8.  **Exit:** Gracefully terminates the application loop, cleaning up all dynamically allocated memory spaces to prevent structural leaks.

---

## 5. Algorithmic Complexity Benchmarks (Big-O)

Your group report must chart and defend the theoretical boundaries of the system operations. The reference complexity expectations are:

| Menu Operation               | Data Structures Involved    | Target Asymptotic Big-O                                |
| :--------------------------- | :-------------------------- | :----------------------------------------------------- |
| **Add Student Request**      | Queue                       | $O(1)$                                                 |
| **Serve Next Student**       | Queue + Linked List + Stack | $O(1)$ or $O(n)$ _depending on pointer implementation_ |
| **Search Completed Service** | Linked List                 | $O(n)$                                                 |
| **Undo Last Service**        | Stack + Linked List + Queue | $O(n)$ _due to sequential deletion inside the list_    |

---

## 6. Individual Component Requirements (50% Marks)

Each team member must claim **one** unique data structure (Queue, Linked List, or Stack) to analyze thoroughly.

- _Note:_ If multiple members evaluate the same structure due to team size constraints, the underlying code blocks, sample tracing values, and narrative discussions must be completely distinct.

### Deliverables for your Individual Section:

1.  **Identity Declaration:** Label your full name, ID, group identifier, and your chosen data structure.
2.  **Structural Mapping:** Describe the architectural purpose and contextual value of the structure within the system.
3.  **Triple-Task Deep Dive:** Pick **three distinct operations** where your structure executes or heavily impacts the workflow.
4.  **Code/Pseudocode Evidence:** Extract precise, clean C code snippets from your group's source text corresponding to these three actions.
5.  **Asymptotic Metrics:** Analyze the Time (Runtime) and Space Complexity using formal Big-O notation. Differentiate between **Best-Case** and **Worst-Case** boundaries where applicable.
6.  **Concrete Execution Tracing:** Provide a mechanical trace walk-through using real values and mathematical indices (_n_ elements) to visually prove your Big-O statements.
7.  **Analytical Reflection:** Author a professional critique highlighting structural constraints, advantages, limitations, and a retrospective evaluation on whether an alternative data structure could optimize performance.

---

## 7. Submission Checklist & Document Construction Sequence

The single, consolidated group submission package must be typewritten and sequentially layered exactly as follows:

- [ ] **1. Cover Page:** Full Course Name, Project Title, Group Number, all Member Names, and Student IDs.
- [ ] **2. Assignment Cover Pages:** Duly completed and formally signed by every active student group member.
- [ ] **3. Problem Narrative & System Architecture Overview:** Detailed background and conceptual flow.
- [ ] **4. Comprehensive C Program Source:** Well-commented, production-grade, and compile-ready codebase.
- [ ] **5. Data Structure Theoretical Breakdown:** Deep architectural rationale for using Queues, Linked Lists, and Stacks.
- [ ] **6. Validation & Execution Proofs:** High-resolution terminal screenshots detailing diverse workflow situations accompanied by original descriptive captions.
- [ ] **7. Collaborative Complexity Summary Matrix:** The complete group Big-O analytical chart.
- [ ] **8. Fragmented Individual Complexities:** Independent, clearly demarcated analysis sections for every single team member.
- [ ] **9. Appendix / Grading Rubrics:** Append any requested assignment assessment rubric layouts.
      \"\"\"
