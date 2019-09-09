# Push_Swap - C - 2019  
Push_Swap focuses on the sorting of stacks in the least amount of moves.  

## WeThinkCode:

**Mandatory:** 86/100  
**Bonus:** 25/25  
**Peers:** 111% (avg)  
  
**Total:** 111/125

## Installation:

To get started, clone the Push_Swap repo and go into the folder:

```
git clone https://github.com/FWMoor/Push_Swap
cd Push_Swap/Push_Swap
```
### Make:    

```
make
```

## Usage:

### Push_Swap:  
```
./push_swap [numbers]  
```  
### Checker:  
```
./checker [-cmosuv] [numbers] 
```  
#### Checker Flags:  
```-c``` - Adds colour to the output/commands/numbers.  
```-m``` - Shows total amount of moves made.  
```-o``` - Shows last command done on stacks.  
```-s``` - Slows down commands in visual mode to 0.5s.  
```-u``` - Displays a usage page.  
```-v``` - Enables visuls modes.  

## Commands:  
### Swap  
```sa``` - Swap the first 2 elements at the top of stack A.  
```sb``` - Swap the first 2 elements at the top of stack B.  
```ss``` - Does ```sa``` and ```sb``` at the same time.  
### Push  
```pa``` - Takes top element of stack B and puts it at the top of stack A.  
```pb``` - Takes top element of stack A and puts it at the top of stack B.  
### Rotate  
```ra``` - Shift up all elements of stack A by 1.  
```rb``` - Shift up all elements of stack B by 1.  
```rr``` - Does ```ra``` and ```rb``` at the same time.  
### Reverse Rotate  
```rra``` - Shift down all elements of stack A by 1.  
```rrb``` - Shift down all elements of stack B by 1.  
```rrr``` - Does ```rra``` and ```rrb``` at the same time.

## Disclaimer:  
Use my code at your own risk!  
I've listed a few names of people that have helped me with ft_ls.  
Be sure to check out their profiles when you have time.

## Helpers
[Calvin](https://github.com/CharlieDeltaZA) - Most of my logic.  
[Verona](https://github.com/veronar) - Memory management, moral support and advice.
