# XMasNameDraw
Automatic name draw for "secret santa" parties.  Supports exluding certain combinations of givers/recipients.

## Syntax
./drawnames <"file.txt">
Where the optional argument is an existing file formatted according to the specifications in the below section.

### Exclude Files
NameDraw supports excluding certain combinations of people from getting each others names in the drawing.
For example, if bill and jill are married, and they shouldn't get each others names in a christmas party of extended family, 
the file should look like this:
`bill-jill`
As you can see, it is fairly straightforward.
Currently, only two names per line are supported.
So you cannot do this:
`bill-jill-judy` to exclude all three from getting each others names.  You must do this:
```bash
bill-jill
bill-judy
jill-judy
```
