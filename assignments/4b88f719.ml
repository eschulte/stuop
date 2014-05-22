class a25 (a10 : string) (a1 : int) =
object (self)
  val mutable a2 = a10
  val mutable a3 = a1
  method a26 a4 = a2 <- a4
  method a27 = a2
  method a28 a5 = a3 <- a5
  method a29 = a3
  method a30 = a3 <- a3 - 1
end;;
module A31 = struct
  type t = a25
  let compare a21 a6 = compare a21#a27 a6#a27
end;;
module A32 = Map.Make(String);;
module A33 = Map.Make(A31);;
let a7 = ref [] in
    try
      while true do
        a7 := (read_line ()) :: !a7
      done
    with _ -> begin
        let a8 = List.fold_left
                   (fun a9 a10 -> A32.add a10
                                          (new a25 a10 0) a9)
                   A32.empty
                   !a7 in
        let a11 = ref true in
        let a12 = List.partition (fun a22 -> a11 := not !a11; !a11) !a7 in
        let a13 = List.combine (fst a12) (snd a12) in
        let a14 = ref A33.empty in
        let a21 = List.iter
                    (fun a15 ->
                     let a16 = A32.find (snd a15) a8 in
                     let a17 = A32.find (fst a15) a8 in
                     let a18 = a17#a28 (a17#a29 + 1) in
                     a14 :=
                       try
                         A33.find a16 !a14 :=
                           a17 :: !(A33.find a16 !a14);
                         !a14
                       with Not_found ->
                         let a19 = ref (a17 :: []) in
                         A33.add a16 a19 !a14)
                    a13 in
        let a20 = ref [] in
        let a21 = A33.iter (fun a22 a23 ->
                            if a22#a29 == 0 then
                              a20 := a22 :: !a20) !a14 in
        let a24 = ref [] in
        let a21 = try
            while (not (A33.is_empty !a14))
                  || (not ((List.length !a20) == 0)) do
              if ((List.length !a20) == 0) then
                failwith "cycle";
              a20 := List.sort (fun a22 a23 ->
                                compare a22#a27 a23#a27) !a20;
              let a25 = List.hd !a20 in
              let a21 = try
                  let edges = A33.find a25 !a14 in
                  List.iter (fun n ->
                             n#a30;
                             if n#a29 == 0 then
                               (a20 := a25 :: n :: (List.tl !a20))) !edges;
                  ()
                with Not_found ->
                  () in
              a24 := a25 :: !a24;
              a20 := List.tl !a20;
              a14 := A33.remove a25 !a14;
            done;
            a24 := List.rev !a24;
            List.iter
              (fun a22 -> print_string (a22#a27 ^ "\n")) !a24;
            ()
          with Failure err ->
            print_string (err ^ "\n");
            () in
        ()
      end
