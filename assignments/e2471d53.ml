let a1 = ref []
and a2 = ref false
and a3 = ref []
and a4 = ref []
and a5 = ref [] in
    try
      while true do
        if !a2 then begin
                   a1 := (read_line ()) :: !a1;
                   a2 := false end
        else begin
            a5 := (read_line ()) :: !a5;
            a2 :=  true end
      done
    with _ -> begin
        for i = 0 to ((List.length !a1)-1) do
          let a6 = List.nth !a1 i in
          if not (List.exists (fun a15 -> a15 = a6) !a5)then
	    a3 := a6 :: !a3;
        done;
        let a7 = ref 0 in
        if ((List.length !a3)=0) then
          a7 := 1;
        while not ((List.length !a3)=0) do
          a3 := List.sort
	          (fun a8 a9 ->
	           compare a8 a9)
	          !a3;
          let a10 = List.hd !a3 in
          a4 := a10:: !a4;
          a3 := List.filter (fun a11 -> not (a10= a11)) !a3;
          for i =0 to ((List.length !a1)-1) do
	    if (a10 = (List.nth !a1 i)) then
	      let a12 = (List.nth !a5 i)
	      and a13 = ref true in
	      a7 := !a7 +1;
	      for a15=0 to ((List.length !a5)-1) do
	        if((List.nth !a5 a15)=a12) then begin
		                               let a14 = List.nth !a1 a15 in
		                               if not (List.exists (fun a15 -> a15 = a14) !a4) then
		                                 a13 := false;
	                                     end
	      done;
	      if (!a13) then
	        a3:= a12 :: !a3;
          done;
        done;
        if (!a7 < ((List.length !a1)-1)) then
          Printf.printf("cycle")
        else
          List.iter print_endline (List.rev !a4);
      end
