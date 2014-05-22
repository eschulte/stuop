type a22 = {a9 : string; mutable a24 : (string list)};;
let a1 = ref [] in
    let a2 = ref [] in
    let a3 = ref [] in
    let a4 = ref [] in
    let a5 = ref false in
    let a6 = ref "" in
    try
      while true do
	let a7 = (read_line()) in
	a1 := a7 :: !a1;
	let a16 a8 a12 = (a12.a9 = a8) in
	let a17 a9 = List.exists (a16 a9) in
	if !a5 then begin
		   a5 := false;
		   if not ((a17 a7) !a2) then begin
				             a2 := {a9=a7; a24=[]} :: !a2;
			                   end;
		   let a10 = ((List.find (a16 !a6)) !a2) in
		   a10.a24 <- a7 :: a10.a24;
		 end else begin
			 a5 := true;
			 a6 := a7;
			 if not ((a17 a7) !a2) then
			   a2 := {a9=a7; a24=[]} :: !a2;
		       end
      done
    with _ -> begin
        begin
	  let a18 a12 =
	    List.length a12.a24 = 0
	  in
	  a3 := List.filter a18 !a2;
	  let a19 a11 a12 =
	    let a20 a13 = begin
		not (a13 = a11.a9)
	      end
	    in
	    let a21 a13 =
	      a13 = a11.a9
	    in
	    if (List.length a12.a24) > 0 then begin
				                   if List.exists a21 a12.a24 then begin
					                                                a12.a24 <- List.filter a20 a12.a24;
					                                                if (List.length a12.a24) = 0 then begin
						                                                                               a3 := a12 :: !a3;
					                                                                                     end
				                                                      end
			                         end
	  in
	  while List.length !a3 != 0 do
	    a3 := List.sort (fun a14 a15 ->
			     compare a14 a15) !a3;
	    let orphan = List.hd !a3
	    in
	    a3 := (match !a3 with
		   |[] -> []
		   |hd :: tl -> tl);
	    a4 := orphan.a9 :: !a4;
	    List.iter (a19 orphan) !a2;
	  done;
	  let checkIfEdges a12 = not ((List.length a12.a24) = 0) in
	  if List.exists checkIfEdges !a2 then begin
			                      print_endline "cycle";
		                            end
	  else begin
	      List.iter print_endline (List.rev !a4);
	    end
	end
      end;;
