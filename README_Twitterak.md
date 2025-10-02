# 🐦 Twitterak (C++ Project)

**Twitterak** is a simple command-line based simulation of a social media platform similar to Twitter.  
Users can sign up, log in, post tweets, like or dislike tweets, view profiles, and even edit their own tweets.  

---

## ✨ Features
- **Login / Signup:** Create a new account or log in to an existing one  
- **Profile display:** View user information (name, biography, birth date, country, link, phone number)  
- **Tweet:** Post new messages  
- **Edit tweets:** Modify the content of existing tweets  
- **Like & Dislike:** React to tweets from other users  
- **View tweets of other users:** Using `@username`  
- **Logout or Delete account:** Log out or permanently delete the account  

---

## 🛠 Build & Run
To compile and run the program:
```bash
g++ twitterak.cpp user.cpp -o twitterak
./twitterak
```

*(Note: `twitterak.hpp`, `user.hpp`, and `user.cpp` must be included in the project.)*  

---

## 📂 Project Structure
- `twitterak.cpp` → Main application logic and user commands  
- `twitterak.hpp` → Class definitions for **Twitterak**  
- `user.cpp / user.hpp` → Implementation of the **User** class (profile and tweets management)  

---

## 📖 Example Commands
```
help
signup
login
profile
tweet Hello Twitterak!
like @user:1
edit tweet 2
logout
exit
```

---

## 👤 Author
**Amir Mohammad Zafari**
