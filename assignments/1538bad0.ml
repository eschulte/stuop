module A14 = Set.Make(String);;
let rec a13 a1 a2 a12 =
  if (List.length !a1) == 0 then [] else
    begin
      a1 := List.sort Pervasives.compare !a1;
      let a3 = (List.hd !a1) in
      a1 := List.tl !a1;
      a12 := a3 :: !a12;
      Hashtbl.remove a2 a3;
      Hashtbl.iter (fun a9 a10 -> if A14.mem a3 a10 then begin
                                                        let a4 = (A14.remove a3 a10) in
                                                        if A14.is_empty a4 then a1 := a9 :: !a1;
                                                        Hashtbl.replace a2 a9 a4 end) a2;
      a13 a1 a2 a12;
    end;;
let a5 = Hashtbl.create 100;;
  try
    while true do
      let a6 = read_line () in
      let a7 = read_line () in
      if not (Hashtbl.mem a5 a6) then Hashtbl.add a5 a6 A14.empty;
      if not (Hashtbl.mem a5 a7) then Hashtbl.add a5 a7 A14.empty;
      Hashtbl.replace a5 a6 (A14.add a7 (Hashtbl.find a5 a6));
    done
  with _ -> begin
      let a8 = ref begin
                   Hashtbl.fold (fun a9 a10 a11 -> if A14.is_empty a10 then a9 :: a11 else a11) a5 []
                 end in
      let a12 = ref [] in
      ignore (a13 a8 a5 a12);
      if (Hashtbl.length a5) > 0 then print_endline "cycle" else List.iter print_endline (List.rev !a12)
    end
