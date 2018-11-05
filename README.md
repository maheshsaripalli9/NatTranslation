# NatTranslation
<p4> PsuedoCode: </p4> 

```
Read the NAT file line by line:


  Store first pair Ip in FirstIp Vector
  
  
  store first pair port in FirstPort vector
  
  
  store second pair in SecondPair Vector
  
  
  
Read the FLOW file line by line: Open Output file with write operation:


  If  IP is equal to any of FirstIp vector strings or *:
  
  
    If port is also equal to corresponding IP Port or *:
    
    
      Write the corresponding NAT.
  If no matches:
    return No matches.
    ```
    
    
If I had more time:
        i would optimized the code using the split function by deliemeter instead of using substr.
        Move the code from main function to seperate function and make code look more cleaner and understandable.
        i would implemented test script using MStest.
        
Intresting Part is i didn't stored any information for FLOW file. Instead compared with NAT file Vectors and parsed the results.



  
    
  
