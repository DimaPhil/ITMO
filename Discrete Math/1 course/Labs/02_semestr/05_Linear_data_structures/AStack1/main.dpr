uses SysUtils;

var 
  m, i, h, size, number : integer;
  c : char;
  x : array of integer;

begin
  reset(input, 'stack1.in');
  rewrite(output, 'stack1.out');
  readln(m);
  size := 1;
  SetLength(x, size);
  h := 0;
  for i := 1 to m do begin
    read(c);
    if (c = '-') then begin
      dec(h);
      writeln(x[h]);
      {if (h * 4 <= size) then begin
        size := size div 2;
        SetLength(x, size);
      end;}
      readln;
    end else begin
      if (h + 1 > size) then begin
        size := size * 2;
        SetLength(x, size);
      end;
      readln(number);
      x[h] := number;     
      inc(h);
    end;
  end;
end.