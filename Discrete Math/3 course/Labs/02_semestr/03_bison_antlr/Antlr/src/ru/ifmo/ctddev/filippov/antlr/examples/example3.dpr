program exampleif;

var a, b : integer;

begin
    a := 5;
    b := 4;
    if (a > b) then begin
        writeln('5 > 4');
    end else begin
        write('5 <= 4');
    end;
    a := a - 2;
    if (a > b) then begin
        writeln('5 > 4');
    end else begin
        write('5 <= 4');
    end;
end.