# 🔐 Playfair Cipher in C++

This is a **simple C++ implementation of the Playfair Cipher** created purely for educational purposes. It helps you understand how the classical Playfair encryption and decryption techniques work. The code is meant to demonstrate the logic and mechanics of the cipher in a clear and minimal way.

---

## 📌 What is the Playfair Cipher?

The **Playfair Cipher** is a manual symmetric encryption technique and was the first digraph substitution cipher. Invented in 1854 by Charles Wheatstone, it encrypts pairs of letters (digraphs), making it more secure than simple monoalphabetic ciphers like Caesar.

The main idea:
1. Construct a 5x5 matrix using a **keyword**.
2. The matrix contains all letters of the alphabet, except 'J' (combined with 'I').
3. The plaintext is split into digraphs (pairs of two letters).
4. Letters in a pair are encrypted based on their positions in the matrix:
   - **Same row:** Replace each with the letter to the right (wrap around).
   - **Same column:** Replace each with the letter below (wrap around).
   - **Different row & column:** Swap columns of the letters (rectangle rule).

---

## 🧠 How This Code Works

- It takes a **key** and builds the 5x5 matrix.
- Treats 'J' as 'I' to fit the 25-letter constraint.
- You can **encode** or **decode** a message:
  - **Encoding** uses the Playfair rules to encrypt the plaintext.
  - **Decoding** reverses those steps.

Example matrix with key `MONARCHY`:

```
M O N A R
C H Y B D
E F G I K
L P Q S T
U V W X Z
```

---

## 🛠 How to Run

1. Make sure you have a C++ compiler (like `g++`) installed.
2. Compile the program:
   ```bash
   g++ playfair.cpp -o playfair
   ```
3. Run it:
   ```bash
   ./playfair
   ```

You'll be prompted to enter:
- A **key** (e.g., `MONARCHY`)
- A **message** to encode or decode

---

Absolutely! Here's how you can add your example to the README in a nicely formatted way:

---

### 🔑 Example

```
Enter the key : trouble
T R O U B 
L E A C D 
F G H I K 
M N P Q S 
V W X Y Z 

1. Encode
2. Decode
Your choice: 2
Enter ciphertext: WGWLOROUBTEADOUBOVROUBTDLRFCFLOUBTEAROUBTDDNXUAZ
Decoded text: NEVERTROUBLEABOUTXTROUBLETILLTROUBLETROUBLESYODX
```

---

## 📦 Features

- Handles uppercase and lowercase input
- Ignores the letter 'J' by treating it as 'I'
- Pads odd-length strings with `'X'` to make valid digraphs
- Implements full **encode** and **decode** logic

---

## 📝 Disclaimer

This code is **not secure** for real-world encryption. It is meant only as a **learning tool** to understand classical ciphers. Modern cryptography is much more complex and secure!

---

## 🤝 Contributing

If you find bugs, have suggestions, or want to expand the project (e.g., support punctuation, better input handling), feel free to fork the repo and send a pull request.

---

## 📚 License

This project is released under the MIT License.

