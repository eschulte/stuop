let a1 = ref [] in
    let a2 = ref [] in
    let a3 = ref [] in
    let a22 a6 a4 = List.exists (fun a5 -> a5 = a6) a4 in
    try
      while true do
	let a16 = read_line() in
	let a15 = read_line() in begin
			        a1 := (a16, a15) :: !a1;
			        if not (List.exists (fun a6 -> a6 = a16) !a2) then
				  a2 := (a16) :: !a2;
			        if not (List.exists (fun a6 -> a6 = a15) !a3) then
			          a3 := (a15) :: !a3;
		              end
      done
    with _ -> begin
        let a7 = ref [] in begin
		          a7 := List.filter (fun a8 -> not (a22 a8 !a2)) !a3;
		          let a9 = ref [] in
		          let a10 = ref (List.length !a7 = 0) in
		          while not !a10 do
		            a7 := List.sort (fun a11 a12 -> compare a11 a12) !a7;
		            a9 := (List.hd !a7) :: !a9;
		            a7 := List.tl !a7;
			    let a13 = ref [] in
			    let a14 = List.hd !a9 in begin
				                    a13 := List.filter (fun (a16, a15) -> a15 = a14) !a1;
				                    for i = 0 to (List.length !a13) - 1 do
					              let a16 = fst (List.nth !a13 i) in
					              let a17 = List.filter (fun (a18, a19) -> (a18 = a16 && a19 <> a14)) !a1 in
					              let a20 = List.length a17 in begin
						                                  if a20 = 0 then a7 := a16 :: !a7;
					                                        end;
				                    done;
				                    a1 := List.filter (fun a21 -> (not (a22 a21 !a13))) !a1;
			                          end;
			                             if (List.length !a7) = 0 then a10 := true;
		          done;
		          a9 := List.rev !a9;
		          if (List.length !a1) = 0 then
			    List.iter print_endline !a9
		          else
			    print_endline "cycle"
	                end
      end
