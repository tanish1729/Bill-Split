# Bill Split
## How to use
1) Run ```g++ BillSplit.cpp -o BillSplit```.
2) Create a file called ```input.txt``` and enter the amounts in it as specified in ```inputFormat.txt```.
3) Run ```./BillSplit input.txt``` to get the split for each person.

### ```inputFormat.txt```
1) Put the person's name followed by space separated item costs (without taxes) in a new line.
2) After all people are done, enter the total tax on bill in a new line. The script divides taxes proportionate to the bill amount for everyone.
3) In a new line after taxes, enter the dutch amount. This amount is equally shared by everyone.

### TO-DO
- [ ] Add colors to output
- [ ] Get the script running on a website