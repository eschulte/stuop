module A15 = Set.Make(String) ;;
let a1 = ref A15.empty in
    let a2 = ref [] in
    let a3 = ref [] in
    let a4 = ref false in
    try while true do
	  let a5=read_line() in
          let a6=read_line() in
    	  a2 := (a6, a5)::!a2;
    	  a1 := A15.add a5 !a1;
    	  a1 := A15.add a6 !a1;
        done
    with a5 ->
      let rec a12 a8 =
        match a8 with
	| [] -> ()
	| h::t -> print_string h; print_string "\n"; a12 t
      in
      let a13 a8 =
	match List.filter (fun a9 -> (snd a9)=a8) !a2 with
	| [] -> true
	| a10 -> false
      in
      let a14 a7 a8 =
	a2 := List.filter (fun a9 -> not ((fst a9)=a8)) !a2;
	a1 := A15.remove a8 !a1;
      in
      let a10 = while not (A15.is_empty !a1) do
	          let a11 = A15.elements (A15.filter a13 !a1) in
	          match a11 with
	          | [] -> a4 := true;
			  a1 := A15.empty
	          | a10 ->	a3 := List.append !a3 a11;
			        List.fold_left a14 () a11
                done in
      if !a4 then print_string "cycle\n"
      else a12 !a3
