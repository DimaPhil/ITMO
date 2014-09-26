uses SysUtils;

const maxn = 100000;
const fictiveValue = 0;

var n, treeSize : integer;
    a : array[0..maxn] of integer;
    tree : array[0..maxn * 4] of integer;

function leftSon(v : integer) : integer;
begin
    result := v * 2;
end;

function rightSon(v : integer) : integer;
begin
    result := v * 2 + 1;
end;

function parent(v : integer) : integer;
begin
    result := v div 2;
end;

function operation(a, b : integer) : integer;
begin
    result := a + b;
end;

procedure buildTree(n : integer);
var i : integer;
begin
    treeSize := 1;
    while (treeSize < n) do
        treeSize := treeSize * 2;
    for i := 0 to n - 1 do
        tree[i + treeSize] := a[i + 1];
    for i := n to treeSize - 1 do 
        tree[i + treeSize] := fictiveValue;
    for i := n - 1 downto 1 do 
        tree[i] := operation(tree[leftSon(i)], tree[rightSon(i)]);
end;

procedure update(v, x : integer);
begin
    v := v + treeSize - 1;
    tree[v] := tree[v] + x;
    v := parent(v);
    while (v > 0) do begin
        tree[v] := operation(tree[leftSon(v)], tree[rightSon(v)]);
        v := parent(v);
    end;
end;

function get_(v, a, b, l, r : integer) : integer;
var m : integer;
begin
    if (l > b) or (a > r) then begin
        result := fictiveValue;
        exit;
    end;
    if (l <= a) and (b <= r) then begin
        result := tree[v];
        exit;
    end;
    m := (a + b) div 2;
    result := operation(get_(leftSon(v), a, m, l, r), get_(rightSon(v), m + 1, b, l, r));
end;

function get(l, r : integer) : integer;
begin
    result := get_(1, treeSize, treeSize * 2 - 1, l + treeSize - 1, r + treeSize - 1);
end;

begin
    n := 5;
    a[1] := 2;
    a[2] := 3;
    a[3] := 1;
    a[4] := -1;
    a[5] := 5;

    buildTree(n);
    writeln(get(2, 3));
    writeln(get(1, 5));
    update(2, -1);
    update(3, 3);
    writeln(get(1, 5));
    writeln(get(2, 4));

    close(input);
    close(output);
end.