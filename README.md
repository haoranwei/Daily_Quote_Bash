### A terminal tool that generates daily quotes when the terminal is opened

### How to run Daily_Quote_Bash?
This project is recommended to deploy the project directory to the root path （"/"）；

#### Prerequisites
#####In Daily_Quote_Bash_generator.cpp,
```c++
FILE* fp = fopen("/Daily_Quote_Bash/quotes.json", "r");
```
####In setup_Daily_Quote_Bash.sh(in shell/).
```bash
if ! grep -q "alias dqb='./Daily_Quote_Bash/Daily_Quote_Bash'" ~/.bashrc; then
echo "alias dqb='./Daily_Quote_Bash/Daily_Quote_Bash'" >> ~/.bashrc
alias dqb='./Daily_Quote_Bash/Daily_Quote_Bash'
```
Please modify the absolute path to prevent the executable file & quotes.json from being not found

#### Setup
```bash
cd Daily_Quote_Bash/
./setup.sh
```

#### Use
In the terminal，enter
```bash
dqb
```



  
