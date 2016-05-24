program arrays;

type array1D = array [1..3] of integer;
     array2D = array [1..3] of array1D;
     array3D = array [1..3] of array2D;

var a : array3D;
    b : array [0..3] of array1D;
    c : array2D;
    i, j, k : integer;

begin
   for i := 1 to 3 do begin
      for j := 1 to 3 do
         for k := 1 to 3 do begin
             a[i, j, k] := i + j + k;
         end;
   end;

   for i := 1 to 3 do
      for j := 1 to 3 do
         b[i, j] := i * j;

   for i := 3 downto 1 do
      for j := 3 downto 1 do begin
         for k := 3 downto 1 do
            write(a[i, j, k], ' ');
         writeln;
      end;
   writeln;

   for i := 1 to 3 do begin
      for j := 1 to 3 do
         write(b[i, j], ' ');
      writeln;
   end;
end.