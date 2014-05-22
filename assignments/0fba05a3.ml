let a1 = ref [] in
    try
      while true do
        a1 := (read_line()) :: !a1
      done
    with _ -> begin
        let a2 = ref (Hashtbl.create (List.length !a1) ) in
        a1 :=  List.rev !a1;
        let a3 = ref 0 in
        while !a3 < (List.length !a1) do
          Hashtbl.add (!a2) (List.nth !a1 !a3) (List.nth !a1 (!a3+1));
          a3 := !a3+2
        done;
        let a17 a4 a15 = if (List.mem a15 a4) then (a4) else (a15 :: a4) in
        let a5 = ref [] in
        List.iter (fun a6 ->
                   a5 := a17 !a5 a6) (!a1);
        a5 := List.sort compare !a5;
        let a7 = ref [] in
        let a8 = ref (List.length !a5) in
        let a9 = ref "" in
        let a10 = ref [] in
        let a11 = ref true in
        let a12 = ref (!a8 + 15) in
        let a13 = ref 0 in
        let a14 = ref false in
        while ((List.length !a7) <> !a8) do
          if (not (List.length !a5 < !a12))
          then (a14 := true;
                a8 := (List.length !a7))
          else (a12 := (List.length !a5);
                a13 := 0;
                while (!a13 < (List.length !a5)) do
                  a9 := (List.nth !a5 !a13);
                  a10 := (Hashtbl.find_all !a2 !a9);
                  a11 := true;
                  List.iter (fun a15 -> a11 := ((List.mem a15 !a7) && !a11)) !a10;
                  if (!a11) then (a7 := !a9 :: !a7;
                                  a5 := List.filter (fun a16 -> (compare !a9 a16) <> 0) !a5;
                                  a13 := (List.length !a5) + 15)
                  else (a13 := !a13+1)
                done)
        done;
        if !a14 then Printf.printf ("cycle") else List.iter print_endline (List.rev !a7)
      end
