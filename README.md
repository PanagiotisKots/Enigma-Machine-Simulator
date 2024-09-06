# 🛡️ Enigma Machine Simulator

A C-based simulation of the Enigma machine encryption.

The Enigma machine is one of the most famous encryption devices in history, used extensively by Nazi Germany during World War II. It became a symbol of cryptographic warfare due to the significant efforts made by the Allies to crack its codes.

---

## 🛠️ Early Development

### 🔨 Invention

- **Inventor**: German engineer Arthur Scherbius.
- **Year**: Patented in 1918, shortly after World War I.
- **Purpose**: Initially designed for commercial use to secure corporate communications.

### 💼 Commercial Models

- **1920s**: Early commercial Enigma models marketed to banks and businesses.
- These models weren’t commercially successful but demonstrated the potential of mechanical encryption devices.

---

## ⚔️ Military Adoption

### 🪖 German Military Interest

- By the **late 1920s** and **early 1930s**, the German military recognized Enigma’s potential for secure communications.
- The military **modified** and enhanced the machine to increase security, adding:
  - Additional **rotors**.
  - The **plugboard** for added complexity.

### 🌍 Usage During WWII

- Enigma became the **primary encryption device** for the German **Army**, **Navy**, **Air Force**, and intelligence services.
- It was believed to be **unbreakable** due to its **complex encryption methods**.










## 🔧 The Enigma Machine Design

| **Component**                 | **Description**                                                                     |
|-------------------------------|-------------------------------------------------------------------------------------|
| ⚙️ **Rotors (Wheels)**         | Rotating disks that scrambled the input letters.                                     |
| 🔄 **Reflector (Umkehrwalze)**  | Reflected signals back through the rotors, ensuring bidirectional encryption.        |
| 🔌 **Plugboard (Steckerbrett)** | Allowed additional letter substitutions for extra complexity.                       |
| ⌨️ **Keyboard**                | Used by the operator to type plaintext messages.                                     |
| 💡 **Lampboard**               | Lit up the encrypted letters in response to each keypress.                          |

### ⚙️ Operation

- Each keypress caused the rotors to move, altering the encryption path for each letter.
- The plugboard provided an additional layer of substitution before and after the signal passed through the rotors.

---

## 🧠 Breaking the Enigma

### 🇵🇱 Polish Efforts

- The first major breakthroughs in cracking Enigma came from **Polish cryptanalysts** in the 1930s.
- Mathematicians **Marian Rejewski**, **Jerzy Różycki**, and **Henryk Zygalski** applied mathematical techniques to study the Enigma’s structure.
- They built early mechanical devices, such as the "**bombe**", to help decipher Enigma messages.

### 🇬🇧 Transfer to the Allies

- In **1939**, just before World War II, Polish cryptanalysts shared their knowledge with **British** and **French intelligence services**.
- This transfer was crucial for further Allied code-breaking efforts.

### 🏰 Bletchley Park

- During World War II, **Bletchley Park** became the hub of Allied cryptanalysis.
- **Alan Turing**, along with **Gordon Welchman** and others, developed advanced versions of the **bombe** machine to automate the decryption of Enigma-encoded messages.

### 🕵️ Impact on the War

- The successful decryption of Enigma-encoded messages, known as "**Ultra**" intelligence, gave the Allies insight into German military operations.
- Historians widely believe that Ultra **shortened the war** and saved countless lives.





## 📜 Post-War and Legacy

### 🔒 Secrecy and Declassification

- The work at **Bletchley Park** remained highly classified until the **1970s**.
- The full extent of the Enigma and code-breaking efforts was not revealed to the public until much later.

### 🏛️ Historical Significance

- The **Enigma machine** has become an iconic symbol in the history of **cryptography** and **warfare**.
- Its story has been the subject of numerous **books**, **documentaries**, and **films**, showcasing the intersection of **technology**, **mathematics**, and **military intelligence**.

### 📚 Additional Resources

- Learn more about **Alan Turing** and the efforts to crack the Enigma code: [**Bletchley Park**](https://bletchleypark.org.uk)
- For an in-depth look at the mathematics behind the Enigma: [**The Bombe Machine**](https://en.wikipedia.org/wiki/Bombe)

---

The **Enigma machine** remains a monumental feat of encryption technology and a critical turning point in the history of cryptography. Its story not only highlights the challenges of secure communications but also the power of human ingenuity in solving complex problems.









# 🛡️ Enigma Machine Simulator

A **C-based simulation** of the historic Enigma machine, demonstrating the encryption process used in this iconic ciphering device. The simulator replicates the step-by-step mechanics of the original machine, allowing users to follow each encryption stage in detail.

## 🔑 Features

- **Full Enigma encryption simulation** including rotor and reflector behavior.
- **Detailed step-by-step output**, displaying the encryption process for each letter.
- **Customizable rotor positions** for flexible configurations and experimentation.
- Easy-to-follow structure with **explanations of each encryption stage** in the output.

## 🛠️ Installation

1. **Clone the repository**:

   ```bash
   git clone https://github.com/PanagiotisKots/Enigma-Machine-Simulator.git

    Navigate to the project directory:

    bash

cd Enigma-Machine-Simulator

Compile the code:

bash

    gcc -o enigma enigma.c

🚀 Usage

To run the Enigma machine simulation:

bash

./enigma

The program will prompt you to enter a message, after which it will display a step-by-step encryption process and the final encrypted message.
⚙️ How It Works
Key Components

    Rotors: Rotating disks that map input letters to other letters. Their positions shift with each key press, dynamically changing the encryption path.
    Reflector: Reflects the signal back through the rotors, adding a second encryption pass.
    Plugboard: (Not implemented in this version) Would allow additional letter substitutions for even greater complexity.

Encryption Process

    Forward Pass Through Rotors: Each input letter is passed through the sequence of rotors, with the rotor positions shifting based on prior encryptions.
    Reflection: The letter is then reflected back through the rotors, further scrambling the signal.
    Backward Pass Through Rotors: The reflected letter is passed again through the rotors in reverse order.
    Rotor Stepping: After each letter, the rotors step, changing their positions and modifying the encryption for the next input.

Example Encryption Output

The program prints out detailed steps for each character's encryption:

plaintext

Encrypting character: A
Initial Rotor Positions: [0, 0, 0]
After Rotor 1: E
After Rotor 2: K
After Rotor 3: Z
After Reflector: R
Back through Rotor 3: X
Back through Rotor 2: P
Back through Rotor 1: G
Encrypted character: G

🔄 Rotor Positioning

The rotor stepping mechanism advances the rotors after each key press, creating a different encryption pattern for each character. You can reset the rotor positions manually or modify them for specific use cases, providing flexibility in your encryption tests.
🧠 Customization

You can easily customize the rotor configurations and starting positions by modifying the code, making it possible to explore different encryption patterns and behaviors.
📄 Example Command

bash

./enigma

Upon running, the program will guide you through the encryption process, outputting the intermediate states and the final encrypted message for any input text.

csharp


This version is concise and focused on the technical aspects of your project, omitting any historical context while detailing the features, components, and usage of your Enigma Machine Simulator.









| 🛠️ **Feature**              | 💡 **Difficulty Level** | 📈 **Complexity**    | 🧠 **Breaking Difficulty** |
|-----------------------------|-------------------------|----------------------|----------------------------|
| ⚙️ **Rotors Mechanism**      | 🟢 Basic Implementation | 🔹 Moderate          | 🟡 Medium                   |
| 🔄 **Rotor Stepping**        | 🟡 Intermediate         | 🔸 High              | 🟠 Challenging              |
| 🔌 **Plugboard (Steckerbrett)** | 🔴 Advanced            | 🔻 Very High         | 🔴 High                     |
| 🔁 **Reflector (Umkehrwalze)** | 🟢 Basic Implementation | 🔹 Moderate          | 🟠 Challenging              |
| 🔍 **Encryption Process**    | 🟡 Intermediate         | 🔸 High              | 🟠 Challenging              |
| 🧮 **Mathematical Model**    | 🔴 Advanced            | 🔻 Very High         | 🔴 High                     |
| 🔐 **Overall Decryption**    | 🔴 Very Advanced       | 🔻 Complex           | 🔴 Very High                |





| 🛠️ **Component**            | 📸 **Image**                                                         | 📄 **Description**                                                                                 |
|-----------------------------|-----------------------------------------------------------------------|-------------------------------------------------------------------------------------------------|
| ⚙️ **Enigma Machine**       | ![Enigma Machine](https://upload.wikimedia.org/wikipedia/commons/thumb/b/bd/Enigma_%28crittografia%29_-_Museo_scienza_e_tecnologia_Milano.jpg/220px-Enigma_%28crittografia%29_-_Museo_scienza_e_tecnologia_Milano.jpg)            | The full Enigma machine, showing the rotors, reflector, and plugboard.                          |
| 🔄 **Rotors**               | ![Rotors](https://upload.wikimedia.org/wikipedia/commons/thumb/d/dd/Enigma_rotors_with_alphabet_rings.jpg/220px-Enigma_rotors_with_alphabet_rings.jpg)                     | The rotating disks (rotors) that scramble the input letters.                                     |
| 🔌 **Plugboard (Steckerbrett)** | ![Plugboard](https://upload.wikimedia.org/wikipedia/commons/thumb/2/27/Enigma-plugboard.jpg/220px-Enigma-plugboard.jpg)              | The plugboard used for additional letter pair substitutions.                                     |
| 🔁 **Reflector (Umkehrwalze)** | ![Reflector](https://upload.wikimedia.org/wikipedia/commons/thumb/b/ba/Enigma_insides.agr.jpg/220px-Enigma_insides.agr.jpg)              | The reflector that sends the electrical signal back through the rotors.                         |




![Enigma Machine](https://example.com/enigma-machine.jpg)
![Enigma Machine](https://example.com/enigma-machine.jpg)
![Enigma Machine](https://example.com/enigma-machine.jpg)
![Enigma Machine](https://example.com/enigma-machine.jpg)
![Enigma Machine](https://example.com/enigma-machine.jpg)
![Enigma Machine](https://example.com/enigma-machine.jpg)
