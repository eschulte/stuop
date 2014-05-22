let a1 = ref [] in
    try
      while true do
        a1 := (read_line ()) :: !a1
      done
    with _ -> begin
        a1 := List.rev !a1;
        let a2 = Hashtbl.create ((List.length !a1) / 2) in
        let a3 = Hashtbl.create ((List.length !a1) / 2) in
        let a4 = ref [] in
        let a5 = ref [] in
        for i = 0 to (List.length !a1) - 1 do
          if not (List.mem (List.nth !a1 i) !a4) then
	    a4 := List.nth !a1 i :: !a4
        done;
        for i = 0 to (List.length !a4) - 1 do
	  Hashtbl.replace a3 (List.nth !a4 i) 0;
        done;
        for i = 0 to (List.length !a1) / 2 - 1 do
          Hashtbl.add a2 (List.nth !a1 (2 * i + 1)) (List.nth !a1 (2 * i));
	  Hashtbl.replace a3 (List.nth !a1 (2 * i)) ((Hashtbl.find a3 (List.nth !a1 (2 * i))) + 1);
        done;
        for i = 0 to (List.length !a4) - 1 do
          let a6 = ref [] in
	  Hashtbl.iter (fun a8 a7 -> if (a7 = 0 && not (List.mem a8 !a5)) then a6 := a8 :: !a6) a3 ;
	  if (List.length !a6) = 0 then
	    begin
	      print_endline "cycle";
	      exit 0
	    end
	  else
	    begin
	      a6 := List.sort compare !a6;
	      a5 := (List.hd !a6) :: !a5;
	      List.iter (fun a8 -> Hashtbl.replace a3 a8 ((Hashtbl.find a3 a8) - 1)) (Hashtbl.find_all a2 (List.hd !a6))
	    end;
	done;
	List.iter print_endline (List.rev !a5)
      end;
