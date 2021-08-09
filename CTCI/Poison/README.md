# Find the Poison Bottle

## About

### Prompt

We have 1000 bottles with 1 of them being poison and 10 test strips to test for poison, each of which can be used only once. 
Test strips sent to the lab have some turn around time. 

### Solution 1

We have enough strips to narrow down the poison bottle if we keep splitting our bottles into two groups since since ```2^10 = 1024```. We start by
splitting the bottle into two groups of 500. We drop a drop from each of these bottles onto the first test strip. After some turn around time, 
the results will show either positive or negative. We continue this process of splitting and testing until the bottle is found.

### Solution 2

The above solution can be represented by a binary tree. At the bottom of the tree are all of the bottles. The path to get to each bottle from the top is unique,
we either go left or right. There's only two directions and we're only going 10 levels deep. So we can use a 10 digit binary number to index each bottle. 
Each digit tells us what direction was taken at each level. 

We index the bottles and look at their binary representations. Take all bottles with a 1 in the rightmost (position 0) position of its binary representation 
and add drops to a strip labeled 0. Next take all bottles with a 1 in position 1 of its binary representation and add drops onto a strip labeled 1. and so on. We send 
all of the strips to the lab and get them back at the same time. A positive value for some strip k means that the poison bottle has a 1 in position k. We construct 
the binary representation of the poison bottle with this info. 

# Usage

Compile and run from the command line

```bash
g++ Bottle.cpp poison.cpp -o output
./output
```