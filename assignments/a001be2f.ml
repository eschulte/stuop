module A25 = Map.Make(String)
let a19 a11 a9 a10 =
  if A25.mem a9 a11 then
    let a1 = A25.find a9 a11 in
    let a1 = a1 @ [a10] in
    A25.add a9 a1 a11
  else
    A25.add a9 [a10] a11
let a20 a11 a9 =
  if A25.mem a9 a11 then
    a11
  else
    A25.add a9 [] a11
let a21 a2 a5 a9 a10 =
  if List.mem a5 a10 then
    let a3 = List.filter (fun a4 -> not(a4 = a5)) a10 in
    a2 := A25.add a9 a3 !a2
  else
    a2 := A25.add a9 a10 !a2
let a22 a11 a5 =
  let a6 = ref A25.empty in
  let a7 = a21 a6 a5 in
  A25.iter a7 a11;
  a6 := A25.remove a5 !a6;
  !a6
let a23 a8 a9 a10 =
  if (List.length a10 = 0) then
    if !a8 = "" then
      a8 := a9
    else if (!a8 > a9) then
      a8 := a9
let a24 a11 =
  let a12 = ref "" in
  let a13 = a23 a12 in
  A25.iter a13 a11;
  !a12;;
let a14 = ref A25.empty in
    try
      while true do
        let a15 = read_line () in
        let a16 = read_line () in
        a14 := a19 !a14 a15 a16;
        a14 := a20 !a14 a16;
      done;
    with _ -> begin
        let a17 = A25.cardinal !a14 in
        let a18 = ref [] in
        try
          while (List.length !a18) != a17 do
            let eliminateString = a24 !a14 in
            if eliminateString = "" then raise Not_found;
            a18 := !a18 @ [eliminateString];
            a14 := a22 !a14 eliminateString;
          done;
          List.iter print_endline !a18;
        with
          Not_found -> Printf.printf "cycle\n"
      end
