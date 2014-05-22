module A16 = Map.Make(String)
let a1 = ref [];;
let a2 = ref A16.empty;;
let a3 = ref A16.empty;;
let a13 a11 a12 = begin
    print_string a11;
    print_string ":";
    print_int a12;
    print_newline ()
  end;;
let a14 a11 a4 = begin
    print_string a11;
    print_string ": {";
    List.iter (fun a12 -> print_endline a12) a4;
    print_endline "}"
  end;;
  try
    while true do
      a1 := !a1@[(read_line ())]
    done
  with _ -> begin
      let a5 = ref 0 in
      while !a5 < List.length !a1 do
        let a6 = List.nth !a1 !a5 in
        let a7 = List.nth !a1 (!a5+1) in
        if A16.mem a6 !a2 then
          a2 := A16.add a6 ((A16.find a6 !a2) + 1) !a2
        else
          a2 := A16.add a6 1 !a2;
        if not (A16.mem a7 !a2) then
          a2 := A16.add a7 0 !a2;
        if A16.mem a7 !a3 then
          a3 := A16.add a7 ((A16.find a7 !a3)@[a6]) !a3
        else
          a3 := A16.add a7 [a6] !a3;
        a5 := !a5 + 2
      done;
      let a8 = ref [] in
      let a15 a9 = begin
          let a10 = ref "" in
          let compare a11 a12 = begin
              if !a10 = "" then
                a10 := a11
              else if (a12 < (A16.find !a10 a9)) || (a12 = (A16.find !a10 a9) && a11 < !a10) then
                a10 := a11
            end in
          A16.iter compare a9;
          if (A16.find !a10 a9) = 0 then
            !a10
          else
            ""
        end in
      while not (A16.is_empty !a2) do
        let min = a15 !a2 in
        if min = "" then begin
                        a8 := ["cycle"];
                        a2 := A16.empty
                      end
        else begin
            a2 := A16.remove min !a2;
            if A16.mem min !a3 then
              List.iter (fun str -> a2 := A16.add str ((A16.find str !a2) - 1) !a2) (A16.find min !a3);
            a8 := !a8@[min]
          end
      done;
      List.iter print_endline !a8
    end
