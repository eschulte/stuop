let a3 = Hashtbl.create 500 in
    let a1 = ref [] in
    let a7 = ref "" in
    let a8 = ref "" in
    try
      while true do
	a7:=read_line();
	a8:=read_line();
	if not (Hashtbl.mem a3 !a7) then Hashtbl.add a3 !a7 [!a8] else Hashtbl.replace a3 !a7 (!a8::(Hashtbl.find a3 !a7));
	if not (Hashtbl.mem a3 !a8) then Hashtbl.add a3 !a8 [] else a8:="";
      done
    with _ -> begin
        let a2 = Hashtbl.length a3 in
        let rec a13 a3 =
          if Hashtbl.length a3 == 0 then if List.length !a1 != a2 then print_string "" else List.iter print_endline (List.rev !a1)
          else
            begin
              let a4 = List.sort (fun a5 a6 -> compare a5 a6) (Hashtbl.fold (fun a7 a8 a9 -> if (List.length a8 == 0) && not (List.mem a7 !a1) then a7::a9 else a9) a3 []) in
              if List.length a4 == 0 then
                begin
                  Hashtbl.clear a3;
                  print_endline "cycle";
                  a13 a3;
                end
              else
                begin
                  Hashtbl.iter (fun a10 a11 -> Hashtbl.replace a3 a10 (List.filter (fun a12->a12 <> (List.hd a4)) a11)) a3;
                  a1 := (List.hd a4) :: !a1;
                  Hashtbl.remove a3 (List.hd a4);
                  a13 a3
                end
            end
        in
        a13 a3
      end
