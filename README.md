# Assignment 6

## Instructions
[Assignment 6 Instructions on Google Drive](https://docs.google.com/document/d/13E2JT0TlCTp4WGOei6YoDP7SJgi6WVe9atXwtc5dIjQ/edit?tab=t.0)

Command to compile, run tests, and cleanup (remove compiled a.out)
```
g++ main.cpp && for t in test*txt; do echo -e "\n\n"; ./a.out < $t; done; rm ./a.out
```
